#include "ModeloServidor.h"

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
    this->buffer.setCantidadBuffers(cantidadMaxClientes);
    this->cantidadClientes = cantidadMaxClientes;
}

void ModeloServidor::setIpYPuerto(std::string ip, std::string puerto)
{
    for(unsigned i = 0; i < this->clientes.size(); ++i) {
        this->clientes[i].setIPPuerto(ip, puerto);
    }
}

void ModeloServidor::aceptarClientes() {
    //Se inicializan todos los clientes.
    std::vector<std::thread> hilos = std::vector<std::thread>(this->clientes.size());
    for(unsigned i = 0; i < this->clientes.size(); ++i) {
        this->clientes[i].setBuffer(&this->buffer);
        this->clientes[i].setBDD(this->bdd);
        this->clientes[i].setCantidadClientes(this->cantidadClientes);
    }

    //Se crean hilos para recibir clientes
    for(unsigned i = 0; i < this->clientes.size(); ++i) {
        hilos[i] = std::thread(&Cliente::aceptarCliente, &this->clientes[i]);
    }

    //Se espera a que todo hilo termine
    for(unsigned i = 0; i < this->clientes.size(); ++i) {
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





void ModeloServidor::enviarARenderizar() {
    for(unsigned i = 0; i < this->clientes.size(); ++i) {
        this->clientes[i].enviarARenderizar();
    }
}

void ModeloServidor::setBDD(std::vector<char> bdd) {
    this->bdd = bdd;
}
