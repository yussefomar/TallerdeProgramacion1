#include "TratarClientesNuevos.h"

TratarClientesNuevos::TratarClientesNuevos(int cantidadClientes)
{
    this->clientes = std::vector<Cliente*>(cantidadClientes);
}

TratarClientesNuevos::~TratarClientesNuevos()
{

}

void TratarClientesNuevos::procesoAEjecutar()
{
    this->socket = new SocketServidor(this->ip, this->puerto);
    if(!this->clientesDesconectados())
    {
        this->rechazarCliente();
        delete this->socket;
    } else {
        Cliente* cliente = this->getClienteDesconectado();
        cliente->intentarReconexion(this->socket);
    }
    return;
}

Cliente* TratarClientesNuevos::getClienteDesconectado() {
    unsigned i;
    for(i = 0; i < this->clientes.size(); ++i) {

        if(!this->clientes[i]->estaConectado()) {
            break;
        }
    }
    return this->clientes[i];
}

bool TratarClientesNuevos::clientesDesconectados()
{
    bool desconectado = false;
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        desconectado |= !this->clientes[i]->estaConectado();
    }
    return desconectado;
}

bool TratarClientesNuevos::clientesConectados()
{
    bool conectados = false;
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        conectados |= this->clientes[i]->estaConectado();
    }
    return conectados;
}

void TratarClientesNuevos::agregarCliente(Cliente* cliente, int i)
{
    this->clientes[i] = cliente;
}

void TratarClientesNuevos::setIpPuerto(std::string ip, std::string puerto)
{
    this->ip = ip;
    this->puerto = puerto;
}

void TratarClientesNuevos::rechazarCliente()
{
    this->socket->enviarByte(0x05);
}
