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

#define ENTIDAD 0
#define EVENTO 1

SocketCliente::SocketCliente(std::string ipServer, std::string puertoServer)
{
    struct addrinfo hints;
    struct addrinfo *posibilidades, *iterador;
    int resultado = 0;
    int posibleSocketFD = 0;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET; /* IP v4*/
    hints.ai_socktype = SOCK_STREAM; /* Protocolo TCP */
    hints.ai_flags = 0;

    std::string ip = ipServer;
    std::string puerto = puertoServer;

    resultado = getaddrinfo(ip.c_str(), puerto.c_str(), &hints, &posibilidades);

    /*Pasar esto a un tipo de enunciado de error en logg del cliente*/
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

    this->estadoSocket = connect(posibleSocketFD,
                                    iterador->ai_addr,
                                    iterador->ai_addrlen) != -1;

    if(this->estadoSocket)
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
    if(this->estadoSocket)
    {
        shutdown(this->socketFD, SHUT_RDWR);
        close(this->socketFD);
    }
}



bool SocketCliente::estaConectado()
{
    return this->estadoSocket > 0;
}

bool SocketCliente::serverDesconectado() {
    return this->estadoSocket == 0;
}



void SocketCliente::enviarByte(char byte)
{
    this->estadoSocket = send(this->socketFD, &byte, sizeof(char), MSG_NOSIGNAL);
}

char SocketCliente::recibirByte()
{
    char byte;
    this->estadoSocket = recv(this->socketFD, &byte, sizeof(char), MSG_NOSIGNAL);
    return byte;
}




void SocketCliente::reconectar(std::string ip, std::string puerto)
{
    shutdown(this->socketFD, SHUT_RDWR);
    close(this->socketFD);

    struct addrinfo hints;
    struct addrinfo *posibilidades, *iterador;
    int resultado = 0;
    int posibleSocketFD = 0;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET; /* IP v4*/
    hints.ai_socktype = SOCK_STREAM; /* Protocolo TCP */
    hints.ai_flags = 0;

    resultado = getaddrinfo(ip.c_str(), puerto.c_str(), &hints, &posibilidades);

    /*Pasar esto a un tipo de enunciado de error en logg del cliente*/
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

    this->estadoSocket = connect(posibleSocketFD,
                                    iterador->ai_addr,
                                    iterador->ai_addrlen) != -1;

    if(this->estadoSocket)
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


std::string SocketCliente::recibirString()
{
    unsigned bytesARecibir = this->recibirByte();
    std::string unString = "";
    unsigned bytesRecibidos = 0;
    char* buffer = new char[bytesARecibir];

    while(bytesRecibidos < bytesARecibir && this->estaConectado() && !this->serverDesconectado())
    {
        this->estadoSocket = recv(this->socketFD, &buffer[bytesRecibidos], bytesARecibir - bytesRecibidos, MSG_NOSIGNAL);
        bytesRecibidos += this->estadoSocket;
    }

    for(unsigned i = 0; i < bytesARecibir && this->estaConectado() && !this->serverDesconectado(); ++i) {
        unString.push_back(buffer[i]);
    }
    delete buffer;
    return unString;
}

void SocketCliente::enviarString(std::string unString)
{
    unsigned bytesAEnviar = unString.size();
    unsigned bytesEnviados = 0;
    char* buffer = new char[bytesAEnviar];
    for(unsigned i = 0; i < unString.size(); ++i) {
        buffer[i] = unString[i];
    }
    this->enviarByte(bytesAEnviar);
    while(bytesEnviados < bytesAEnviar && this->estaConectado() && !this->serverDesconectado())
    {
        this->estadoSocket = send(this->socketFD, &buffer[bytesEnviados], bytesAEnviar - bytesEnviados, MSG_NOSIGNAL);
        bytesEnviados += this->estadoSocket;
    }
    delete buffer;
}
