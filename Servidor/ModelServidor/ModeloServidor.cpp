#include "ModeloServidor.h"
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

#define RECHAZADO 0xFF

ModeloServidor::ModeloServidor()
{

}

ModeloServidor::~ModeloServidor()
{

}

//METODOS PARA LA INSTANCIA DE ACEPTAR CLIENTES
void ModeloServidor::setClientesPermitidos(unsigned cantidadMaxClientes)
{
    this->clientes = std::vector<Cliente>(cantidadMaxClientes);
    this->reconectores = std::vector<Reconector>(cantidadMaxClientes);
    this->buffer.setCantidadBuffers(cantidadMaxClientes);
    this->backups = std::vector<std::string>(this->clientes.size());

}

void ModeloServidor::setIpYPuerto(std::string ip, std::string puerto)
{
    this->ip = ip;
    this->puerto = puerto;
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i].setIPPuerto(ip, puerto);
    }
}

void ModeloServidor::aceptarClientes()
{
    //Se inicializan todos los clientes.
    std::vector<std::thread> hilos = std::vector<std::thread>(this->clientes.size());
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i].setBuffer(&this->buffer);
        this->clientes[i].setBDD(this->bdd);
        this->clientes[i].setCantidadClientes(this->clientes.size());
    }
    for(unsigned i = 0; i < this->reconectores.size(); ++i)
    {
        this->reconectores[i].setCliente(&this->clientes[i]);
        this->reconectores[i].setMutexReconexion(&this->mutexReconexion);
    }
    //Se crean hilos para recibir clientes
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        hilos[i] = std::thread(&Cliente::aceptarCliente, &this->clientes[i]);
    }

    //Se espera a que todo hilo termine
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        hilos[i].join();
    }
}

//METODOS PARA LA INSTANCIA DE JUEGO
void ModeloServidor::enviarMensajes()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i].enviarMensaje();
    }
    return;
}

void ModeloServidor::recibirMensajes()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i].recibirMensaje();
    }
    return;
}

bool ModeloServidor::clientesEstanConectados()
{
    bool estanConectados = false;

    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        estanConectados |= this->clientes[i].estaConectado();
    }
    return estanConectados;
}




void ModeloServidor::permitirInicio()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i].permitirInicio();
    }
    return;
}



char ModeloServidor::hashear(std::string unString)
{
    char code = 0X00;
    char caracter = 0X00;

    int hasha = 7;
    for(unsigned i = 0; i < unString.size(); ++i)
    {
        caracter = unString[i];
        hasha = hasha*31 + caracter;
    }
    code = hasha;
    return code;
}

void ModeloServidor::enviarARenderizar()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i].enviarARenderizar();
    }
}

void ModeloServidor::setBDD(std::vector<char> bdd)
{
    this->bdd = bdd;
}

void ModeloServidor::lanzarHiloDeReconexion()
{
    while (this->clientesEstanConectados())
    {
        this->hiloDeReconexion = std::thread(&ModeloServidor::hiloDeAnalisisDeReconexion, this);
        this->hiloDeReconexion.join();

    }

}

void ModeloServidor::hiloDeAnalisisDeReconexion()
{
    std::mutex mutexAHR;
    SocketServidor* socketReconexion = new SocketServidor(this->ip, this->puerto);


    bool socketReconexionAdoptado = false;


    for(unsigned i = 0; i < this->reconectores.size() && !socketReconexionAdoptado; ++i)
    {
        socketReconexionAdoptado |= this->reconectores[i].analizarSocketReconexion(socketReconexion);
    }

    if(!socketReconexionAdoptado)
    {
        socketReconexion->enviarByte(RECHAZADO);
        socketReconexion->enviarByte(RECHAZADO);
        delete socketReconexion;
    }
}

void ModeloServidor::recibirBackup() {
    this->backupElegido = 0;
    for(unsigned i = 0; i < this->clientes.size(); ++i) {
        this->backups[i] = this->clientes[i].recibirBackup();
        if(this->backups[i].size()) {
            backupElegido = i;
        }
    }
}

void ModeloServidor::enviarBackup() {
    for(unsigned i = 0; i < this->reconectores.size(); ++i) {
        this->reconectores[i].enviarBackup(this->backups[this->backupElegido]);
    }
}
