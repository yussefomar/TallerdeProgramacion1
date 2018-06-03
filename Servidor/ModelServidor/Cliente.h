#ifndef CLIENTE_H
#define CLIENTE_H

#include "Buffer.h"
#include <list>
#include "../SocketServidor/SocketServidor.h"
#include <vector>
#include <thread>
#include <mutex>
#include <queue>

class Cliente
{
public:
    Cliente();
    virtual ~Cliente();

    void setIPPuerto(std::string ip, std::string puerto);
    void setBuffer(Buffer* buffer);
    void setBDD(std::vector<char> bdd);
    void aceptarCliente();

    void recibirMensaje();
    void enviarMensaje();
    bool estaConectado();
    void permitirInicio();
    void enviarARenderizar();
    void avisarDesconexion();
    void setCantidadClientes(unsigned cantidad);


protected:

private:
    static std::queue<char> usuariosIngresados;
    static std::mutex mutexIngresos;
    static int contadorClientes;

    unsigned idCliente;
    Buffer* buffer;
    SocketServidor* socket;
    std::string ip;
    std::string puerto;
    std::vector<char> bdd;
    char credencial;
    unsigned cantidadClientes;

};

#endif // CLIENTE_H
