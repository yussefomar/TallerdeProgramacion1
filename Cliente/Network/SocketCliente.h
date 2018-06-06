#ifndef SOCKETCLIENTE_H
#define SOCKETCLIENTE_H

#include <string>

class SocketCliente
{
public:
    SocketCliente(std::string ipServer, std::string puertoServer);
    virtual ~SocketCliente();
    //si el socket send o recv devuelve 0 es porque cerraron del otro lado. el server se murio.
    //ver ese tema
    bool estaConectado();
    bool serverDesconectado();
    char recibirByte();
    void enviarByte(char byte);
    void enviarString(std::string unString);
    std::string recibirString();
    void reconectar(std::string ip, std::string puerto);

protected:

private:
    int socketFD;
    int estadoSocket;

};

#endif // SOCKETCLIENTE_H
