#ifndef CLIENTE_H
#define CLIENTE_H

#include "Buffer.h"
#include <list>
#include "../SocketServidor/SocketServidor.h"

class Cliente
{
public:
    Cliente(Buffer* buffer, std::string ip, std::string puerto);
    virtual ~Cliente();
    void recibirMensaje();
    void enviarMensaje();
    bool estaConectado();
    bool hayCambios();
    void enviarId(unsigned id);
    char recibirUsuario();
    char recibirPassword();
    void enviarRespuesta(char codigo);
    char nombreUsuario;
    char passwordUsuario;
    unsigned getID();
    void actuarFrenteADesconexion();
    void intentarReconexion(SocketServidor* socketNuevo);
    void enviarARenderizar();

protected:

private:
    static int contadorClientes;
    unsigned id;
    Buffer* buffer;
    SocketServidor* socket;
};

#endif // CLIENTE_H
