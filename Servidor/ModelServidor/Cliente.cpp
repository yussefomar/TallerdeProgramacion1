#include "Cliente.h"
#include <iostream>



#define DECVELX 0x00
#define DECVELY 0x01
#define INCVELX 0x02
#define INCVELY 0x03
#define STOPJUG 0x04
#define ACCJUG 0x05
#define DESJUG 0x06
#define PATPELO 0x07
#define RECUPELO 0x08
#define CAMBJUG 0x09
#define COMMNULL 0x0A
#define PASPELO 0x0B
#define DEFLOCAL 0x0C
#define DEFVISIT 0x0D //cuidado con estos dos ultimos comandos.
#define DESCJUG 0x0E
#define NECRENDER 0X0F
#define ARMARBACKUP 0x10


#define ENTIDAD 0
#define EVENTO 1

#define TODOOK 0x01
#define NOTOK 0x00


Cliente::Cliente() : idCliente(++contadorClientes)
{
    this->socket = nullptr;
}

Cliente::~Cliente()
{
    if(this->socket != nullptr)
    {
        delete this->socket;
    }
}

void Cliente::setIPPuerto(std::string ip, std::string puerto)
{
    this->ip = ip;
    this->puerto = puerto;
}


void Cliente::setBuffer(Buffer* buffer)
{
    this->buffer = buffer;
}
void Cliente::setBDD(std::vector<char> bdd)
{
    this->bdd = bdd;
}
std::mutex Cliente::mutexIngresos;
std::queue<char> Cliente::usuariosIngresados;

void Cliente::aceptarCliente()
{
    Cliente::mutexIngresos.lock();
    std::cout << "Este hilo es el nro: "<< this->idCliente << std::endl;
    Cliente::mutexIngresos.unlock();

    bool credencialesRepetidas = true;
    bool credencialesValidas = false;
    this->socket = new SocketServidor(this->ip, this->puerto);
    this->socket->enviarByte(this->idCliente);
    this->socket->enviarByte(this->cantidadClientes);

    Cliente::mutexIngresos.lock();
    std::cout << "Generando user en el hilo nro: "<< this->idCliente << std::endl;
    Cliente::mutexIngresos.unlock();

    while(credencialesRepetidas)
    {
        Cliente::mutexIngresos.lock();
        this->credencial = this->socket->recibirByte();
        credencialesRepetidas = Cliente::usuariosIngresados.front() == this->credencial;
        if(credencialesRepetidas)
        {
            this->socket->enviarByte(LI_NOMBRE_REPETIDO);
        }
        Cliente::mutexIngresos.unlock();
    }

    Cliente::mutexIngresos.lock();
    std::cout << "Generando pass en el hilo nro: "<< this->idCliente << std::endl;
    Cliente::mutexIngresos.unlock();

    while(!credencialesValidas)
    {
        for(unsigned i = 0; i < this->bdd.size() && !credencialesValidas; ++i)
        {
            credencialesValidas = this->bdd[i] == this->credencial;
        }
        if(!credencialesValidas)
        {
            this->socket->enviarByte(LI_CREDENCIALES_ERROR);
            this->credencial = this->socket->recibirByte();


        }

    }
    Cliente::mutexIngresos.lock();
    std::cout << "push un cambio en el hilo nro: "<< this->idCliente << std::endl;
    Cliente::mutexIngresos.unlock();

    Cliente::mutexIngresos.lock();
    Cliente::usuariosIngresados.push(this->credencial);
    Cliente::mutexIngresos.unlock();
    this->socket->enviarByte(LI_CREDENCIALES_OK);
}

int Cliente::contadorClientes = -1;

void Cliente::enviarMensaje()
{
    if(!this->estaConectado())
    {
        return;
    }
    char codigo = this->buffer->popCodigo(this->idCliente);
    this->socket->enviarByte(codigo);
    this->avisarDesconexion();
}

void Cliente::recibirMensaje()
{
    if(!this->estaConectado())
    {
        return;
    }
    char codigo = this->socket->recibirByte();
    this->buffer->pushCodigo(codigo);
    this->avisarDesconexion();
}

bool Cliente::estaConectado()
{
    return this->socket->estaConectado();
}




void Cliente::permitirInicio()
{
    this->socket->enviarByte(TODOOK);
}

void Cliente::enviarARenderizar()
{
    this->socket->enviarByte(NECRENDER);
}

void Cliente::avisarDesconexion()
{
    if(!this->estaConectado())
    {
        this->buffer->pushCodigo(DESCJUG);
    }
}

void Cliente::setCantidadClientes(unsigned cantidad)
{
    this->cantidadClientes = cantidad;
}

unsigned Cliente::getIdCliente()
{
    return this->idCliente;
}

unsigned Cliente::getCantidadClientes()
{
    return this->cantidadClientes;
}

char Cliente::getCredencial()
{
    return this->credencial;
}

void Cliente::enviarPedidoBackup()
{
    if(!this->estaConectado())
    {
        this->buffer->pushCodigo(ARMARBACKUP);
    }
}

std::string Cliente::recibirBackup()
{
    if(this->socket->estaConectado()) {
            return this->socket->recibirString();

    }
    std::string backupNulo = "";
    return backupNulo;
}

void Cliente::enviarBackup(std::string backup)
{
    this->socket->enviarString(backup);
}

void Cliente::setSocket(SocketServidor* socket)
{
    delete this->socket;
    this->socket = socket;
}
