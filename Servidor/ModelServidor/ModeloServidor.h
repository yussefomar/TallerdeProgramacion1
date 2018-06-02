#ifndef MODELOSERVIDOR_H
#define MODELOSERVIDOR_H

#include "Cliente.h"
#include <vector>
#include <thread>
#include <mutex>
/*#include "Buffer.h"*/

class ModeloServidor
{
public:
    ModeloServidor();
    virtual ~ModeloServidor();

    void aceptarClientes();

    void enviarMensajes();
    void recibirMensajes();

    bool clientesEstanConectados();

    char hashear(std::string unString);

    void setClientesPermitidos(unsigned cantidadMaxClientes);
    void setIpYPuerto(std::string ip, std::string puerto);
    void permitirInicio();
    void enviarARenderizar();
    void setBDD(std::vector<char> bdd);
protected:

private:
    Buffer buffer;
    std::vector<Cliente> clientes;
    std::queue<char> clientesIngresados;
    std::mutex mutex;
    std::vector<char> bdd;

};

#endif // MODELOSERVIDOR_H
