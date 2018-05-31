#ifndef TRATARCLIENTESNUEVOS_H
#define TRATARCLIENTESNUEVOS_H

#include "Thread.h"
#include "Cliente.h"


class TratarClientesNuevos : public Thread
{
    public:
        TratarClientesNuevos(int cantidadDeClintes);
        virtual ~TratarClientesNuevos();
        void procesoAEjecutar();
        void agregarCliente(Cliente* cliente, int i);
        void setIpPuerto(std::string ip, std::string puerto);
        bool clientesConectados();
        bool clientesDesconectados();
        void rechazarCliente();
        Cliente* getClienteDesconectado();


    protected:

    private:
        std::vector<Cliente*> clientes;
        SocketServidor* socket;
        std::string ip;
        std::string puerto;

};

#endif // TRATARCLIENTESNUEVOS_H
