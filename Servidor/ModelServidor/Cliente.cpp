#include "Cliente.h"
#include <iostream>

#define LI_NOMBRE_OK 0X0B //NOMBRE CORRECTO.
#define LI_NOMBRE_ERROR 0X0C //NOMBRE INCORRECTO.
#define LI_NOMBRE_REPETIDO 0X0D //NOMBRE EXISTENTE.
#define LI_CREDENCIALES_OK 0X0E //CREDENCIALES CORRECTAS.
#define LI_CREDENCIALES_ERROR 0X0F //CREDENCIALES INCORRECTAS.
#define LI_CONSULTO_INICIO 0X11 //ME PREGUNTAN SI SE INICIO.
#define LI_INICIO_OK 0X12 //RESPONDO QUE ESTAN TODOS CONECTADOS.

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
void Cliente::setBDD(std::vector<char> usuarios, std::vector<char> passwords)
{
    this->usuarios = usuarios;
    this->passwords = passwords;
}
std::mutex Cliente::mutexIngresos;
std::queue<char> Cliente::usuariosIngresados;

void Cliente::aceptarCliente()
{
    Cliente::mutexIngresos.lock();
    std::cout << "Este hilo es el nro: "<< this->idCliente << std::endl;
    Cliente::mutexIngresos.unlock();

    bool usuarioValido = false;
    bool passValido = false;
    this->socket = new SocketServidor(this->ip, this->puerto);
    this->socket->enviarByte(this->idCliente);

    Cliente::mutexIngresos.lock();
    std::cout << "Generando user en el hilo nro: "<< this->idCliente << std::endl;
    Cliente::mutexIngresos.unlock();

    while(!usuarioValido)
    {
        Cliente::mutexIngresos.lock();
        this->nombre = this->socket->recibirByte();
        usuarioValido = Cliente::usuariosIngresados.empty();
        usuarioValido |= Cliente::usuariosIngresados.front() != this->nombre;
        if(!usuarioValido)
        {
            this->socket->enviarByte(LI_NOMBRE_REPETIDO);
        }
        Cliente::mutexIngresos.unlock();
    }
    this->socket->enviarByte(LI_NOMBRE_OK);

    Cliente::mutexIngresos.lock();
    std::cout << "Generando pass en el hilo nro: "<< this->idCliente << std::endl;
    Cliente::mutexIngresos.unlock();

    while(!passValido)
    {
        this->pass = this->socket->recibirByte();
        for(unsigned i = 0; i < this->usuarios.size() && !passValido; ++i)
        {
            passValido = this->usuarios[i] == this->nombre;
            passValido &= this->passwords[i] == this->pass;
        }
        if(!passValido)
        {
            this->socket->enviarByte(LI_CREDENCIALES_ERROR);
        }

    }
    Cliente::mutexIngresos.lock();
    std::cout << "push un cambio en el hilo nro: "<< this->idCliente << std::endl;
    Cliente::mutexIngresos.unlock();

    Cliente::mutexIngresos.lock();
    Cliente::usuariosIngresados.push(this->nombre);
    Cliente::mutexIngresos.unlock();
    this->socket->enviarByte(LI_CREDENCIALES_OK);
}

int Cliente::contadorClientes = -1;

void Cliente::enviarMensaje()
{
    if(!this->estaConectado())
        return;
    char codigo = this->buffer->popCodigo(this->idCliente);
    this->socket->enviarByte(codigo);
}

void Cliente::recibirMensaje()
{
    if(!this->estaConectado())
        return;
    char codigo = this->socket->recibirByte();
    this->buffer->pushCodigo(codigo);
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
