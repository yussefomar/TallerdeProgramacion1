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
    void setBDD(std::vector<char> usuarios, std::vector<char> passwords);
    void aceptarCliente();

    void recibirMensaje();
    void enviarMensaje();
    bool estaConectado();
    void permitirInicio();
    void enviarARenderizar();


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
    std::vector<char> usuarios;
    std::vector<char> passwords;
    char nombre;
    char pass;

};

#endif // CLIENTE_H
