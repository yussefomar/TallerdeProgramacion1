#ifndef SOCKETCLIENTE_H
#define SOCKETCLIENTE_H

#include <string>

class SocketCliente
{
public:
    SocketCliente(std::string ipServer, std::string puertoServer);
    virtual ~SocketCliente();

    void enviarCodigoComando(std::string codigo);
    unsigned recibirCantidadCambios();
    bool estaConectado();
    std::string recibirCodigoComando();
    char recibirByte();
    void enviarByte(char byte);
    void enviarPedidoDeCambios();
    unsigned recibirIdCliente();

protected:

private:
    int socketFD;
    bool socketConectado;

};

#endif // SOCKETCLIENTE_H
