#include "SocketCliente.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>

#include <iostream>

#include <string.h>
#include <stdio.h>
#include <errno.h>

#include <stdbool.h>

#define LOCALHOST "localhost" //ojala sea este
#define PUERTOSERVER "8080"

#define SIZECOMMAND 2
#define SIZEBYTE 1

SocketCliente::SocketCliente()
{
    struct addrinfo hints;
    struct addrinfo *posibilidades, *iterador;
    int resultado = 0;
    int posibleSocketFD = 0;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET; /* IP v4*/
    hints.ai_socktype = SOCK_STREAM; /* Protocolo TCP */
    hints.ai_flags = 0;

    std::string ip = LOCALHOST;
    std::string puerto = PUERTOSERVER;

    resultado = getaddrinfo(ip.c_str(), puerto.c_str(), &hints, &posibilidades);

    /*Pasar esto a un tipo de enunciado de error en logg del servidor*/
    if (resultado != 0)
    {
        std::cerr << "ERROR EN ADDRINFO: " << gai_strerror(resultado) << std::endl;
        return;
    }

    iterador = posibilidades;
    bool direccionValida = false;
    while (iterador != NULL && !direccionValida)
    {
        posibleSocketFD = socket(iterador->ai_family,
                                 iterador->ai_socktype,
                                 iterador->ai_protocol);
        if (posibleSocketFD != -1)
        {
            direccionValida = true;
            std::cout << "direccion valida" << std::endl;
        }
        else
        {
            iterador = iterador->ai_next;

        }
    }

    if (!direccionValida)
    {
        std::cerr << "NO SE OBTUVIERON DIRECCIONES VALIDAS" << std::endl;
    }

    this->socketConectado = connect(posibleSocketFD,
                                    iterador->ai_addr,
                                    iterador->ai_addrlen) != -1;

    if(this->socketConectado)
    {
        this->socketFD = posibleSocketFD;

    }
    else
    {
        std::cerr << "NO SE PUDO CONECTAR" << std::endl;
        close(posibleSocketFD);
    }

    freeaddrinfo(posibilidades);


}

SocketCliente::~SocketCliente()
{
    if(this->socketConectado)
    {
        shutdown(this->socketFD, SHUT_RDWR);
        close(this->socketFD);
    }
}

void SocketCliente::enviarCodigoComando(std::string comando)
{
    char byte;

    /*envia el primer byte: la entidad*/
    byte = comando[0];
    if(send(this->socketFD, &byte, SIZEBYTE, MSG_NOSIGNAL) <= 0)
    {
        std::cerr << "ERROR EN SEND" << std::endl;
        this->socketConectado = false;
    }

    /*recibimos el segundo byte: el evento*/
    byte = comando[1];
    if(send(this->socketFD, &byte, SIZEBYTE, MSG_NOSIGNAL) <= 0)
    {
        std::cerr << "ERROR EN SEND" << std::endl;
        this->socketConectado = false;
    }

    if(!this->socketConectado)
    {
        //hacer algo al respecto
    }

}

std::string SocketCliente::recibirCodigoComando()
{
    std::string comando;
    char byte;

    /*recibimos el primer byte: la entidad*/
    if(recv(this->socketFD, &byte, SIZEBYTE, MSG_NOSIGNAL) <= 0)
    {
        std::cerr << "ERROR EN RECV" << std::endl;
        this->socketConectado = false;
    }
    comando.push_back(byte);

    /*recibimos el segundo byte: el evento*/
    if(recv(this->socketFD, &byte, SIZEBYTE, MSG_NOSIGNAL) <= 0)
    {
        std::cerr << "ERROR EN RECV" << std::endl;
        this->socketConectado = false;
    }
    comando.push_back(byte);


    if(!this->socketConectado)
    {
        //hacer algo al respecto
    }


    return comando;
}

