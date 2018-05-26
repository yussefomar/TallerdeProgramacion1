#ifndef SOCKETCLIENTE_H
#define SOCKETCLIENTE_H

#include <string>

class SocketCliente
{
public:
    SocketCliente(std::string ipServer, std::string puertoServer);
    virtual ~SocketCliente();

    bool estaConectado();
    char recibirByte();
    void enviarByte(char byte);

    char recibirIdCliente();

protected:

private:
    int socketFD;
    bool socketConectado;

};

#endif // SOCKETCLIENTE_H
