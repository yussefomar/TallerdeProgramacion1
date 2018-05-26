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

    char entidad = comando[ENTIDAD];
    char evento = comando[EVENTO];
    byte = entidad << 4;
    byte = byte | evento;
    this->enviarByte(byte);
}

unsigned SocketCliente::recibirCantidadCambios()
{
    char cantidadCambios = 0x00;
    cantidadCambios = this->recibirByte();
    return cantidadCambios;
}

bool SocketCliente::estaConectado()
{
    return this->socketConectado;
}

std::string SocketCliente::recibirCodigoComando()
{
    std::string comando;
    char byte;

    byte = this->recibirByte();
    char entidad = byte >> 4;
    comando.push_back(entidad);
    char evento = byte & 0x0F;
    comando.push_back(evento);

    return comando;
}

void SocketCliente::enviarByte(char byte)
{
    this->socketConectado = send(this->socketFD, &byte, sizeof(char), MSG_NOSIGNAL) > 0;
}

char SocketCliente::recibirByte()
{
    char byte;
    this->socketConectado = recv(this->socketFD, &byte, sizeof(char), MSG_NOSIGNAL) > 0;
    return byte;
}

void SocketCliente::enviarPedidoDeCambios()
{
    char byte = 0xFF;
    this->enviarByte(byte);
    this->enviarByte(byte);
}

unsigned SocketCliente::recibirIdCliente() {
    char idChar = this->recibirByte();
    unsigned idCliente = idChar;
    return idCliente;
}
