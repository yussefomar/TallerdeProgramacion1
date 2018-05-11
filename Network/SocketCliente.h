#ifndef SOCKETCLIENTE_H
#define SOCKETCLIENTE_H

#include <string>

class SocketCliente
{
public:
    SocketCliente();
    virtual ~SocketCliente();

    void enviarCodigoComando(std::string codigo);
    void enviarCodigoComandoNulo();
    char recibirCantidadCambios();
    bool estaConectado();
    std::string recibirCodigoComando();

protected:

private:
    int socketFD;
    bool socketConectado;
};

#endif // SOCKETCLIENTE_H
