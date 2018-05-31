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

#define ENTIDAD 0
#define EVENTO 1

#define DESCJUG 0x0E

Cliente::Cliente(Buffer* buffer, std::string ip, std::string puerto) :
    id(++Cliente::contadorClientes),
    buffer(buffer)
{
    this->socket = new SocketServidor(ip, puerto);
}

Cliente::~Cliente()
{
    if(this->socket == nullptr) return;
    delete this->socket;
}

int Cliente::contadorClientes = -1;

void Cliente::enviarMensaje()
{
    if(!this->estaConectado()) return;
    char codigo = this->buffer->popCodigo(this->id);
    this->socket->enviarByte(codigo);
    this->actuarFrenteADesconexion();
}

void Cliente::recibirMensaje()
{
    if(!this->estaConectado()) return;
    char codigo = this->socket->recibirByte();
    this->buffer->pushCodigo(codigo);
    this->actuarFrenteADesconexion();
}

bool Cliente::estaConectado()
{
    return this->socket->estaConectado();
}

bool Cliente::hayCambios()
{
    return this->buffer->cantidadCodigos(this->id) > 0;
}

void Cliente::enviarId(unsigned id)
{
    char idCaracter = id;
    this->socket->enviarByte(idCaracter);
}

void Cliente::enviarRespuesta(char codigo)
{
    this->socket->enviarByte(codigo);
}

char Cliente::recibirUsuario()
{
    char codigo = this->socket->recibirByte();
    return codigo;
}

char Cliente::recibirPassword()
{
    char codigo = this->socket->recibirByte();
    return codigo;
}

unsigned Cliente::getID() {
    return this->id;
}

void Cliente::actuarFrenteADesconexion() {
    if(this->estaConectado()) return;
    char id = this->id;
    id = id << 6;
    char code = id | DESCJUG;
    this->buffer->pushCodigo(code);
}

void Cliente::intentarReconexion(SocketServidor* socket) {
    delete this->socket;
    this->socket = socket;
}

void Cliente::enviarARenderizar() {
    this->socket->enviarByte(NECRENDER);
}
