#include "ModeloCliente.h"
#include "../Network/ControllerNet/DisminuirVelocidadYNet.h"
#include "../Network//ControllerNet/AumentarVelocidadYNet.h"
#include "../Network//ControllerNet/DisminuirVelocidadXNet.h"
#include "../Network//ControllerNet/AumentarVelocidadXNet.h"
#include "../Network//ControllerNet/CambiarJugadorNet.h"
#include "../Network//ControllerNet/StopJugadorNet.h"
#include "../Network//ControllerNet/AcelerarNet.h"
#include "../Network//ControllerNet/DesacelerarNet.h"
#include "../Network//ControllerNet/PatearPelotaNet.h"

#include "../Network/CommandNet.h"
#include "../Network/ControllerNet/RecuperarPelotaNet.h"
#define CANTCOMMANDS 10

ModeloCliente::ModeloCliente(Model* model)
{
    this->model = model;
     this->commands = std::vector<CommandNet*>(CANTCOMMANDS);
    this->commands[NDECVELX] = new DisminuirVelocidadXNet(model);
    this->commands[NDECVELY] = new DisminuirVelocidadYNet(model);
    this->commands[NINCVELX] = new AumentarVelocidadXNet(model);
    this->commands[NINCVELY] = new AumentarVelocidadYNet(model);
    this->commands[NCAMBJUG] = new CambiarJugadorNet(model);
    this->commands[NSTOPJUG] = new StopJugadorNet(model);
    this->commands[NACCJUG] = new AcelerarNet(model);
    this->commands[NDESJUG] = new DesacelerarNet(model);

    this->commands[ NPATPELO] = new PatearPelotaNet(model);
    this->commands[NRECUPELO] = new RecuperarPelotaNet(model);
}

ModeloCliente::~ModeloCliente()
{
    //dtor
}

/*El modelo cliente puede devolver datos que son necesarios*/
Pelota* ModeloCliente::getPelota()
{
    return this->model->getPelota();
}

Jugador* ModeloCliente::getJugadorNro(int i)
{
    return this->model->getJugadorNro(i);
}

Jugador* ModeloCliente::getJugadorActivo()
{
    return this->model->getJugadorActivo();
}

std::string ModeloCliente::getCasaca()
{
    return this->model->getCasaca();
}
/*El modelo cliente no deberia modificar al modelo*/
void ModeloCliente::setCamara(SDL_Rect* camara)
{
    return;
}

void ModeloCliente::setFormacion(Formacion* formacion)
{
    return;
}

void ModeloCliente::setCasaca(std::string casacaName)
{
    return;
}

void ModeloCliente::jugadorActivoAumentaVelocidadEnX()
{
    return;
}
void ModeloCliente::jugadorActivoAumentaVelocidadEnY()
{
    return;
}
void ModeloCliente::jugadorActivoDisminuyeVelocidadEnX()
{
    return;
}
void ModeloCliente::jugadorActivoDisminuyeVelocidadEnY()
{
    return;
}
void ModeloCliente::jugadorActivoAcelera()
{
    return;
}
void ModeloCliente::jugadorActivoDesacelera()
{
    return;
}
void ModeloCliente::jugadorActivoPateaPelota()
{
    return;
}
void ModeloCliente::jugadorActivoRecuperaPelota()
{
    return;
}
void ModeloCliente::jugadorActivoDetener()
{
    return;
}
void ModeloCliente::cambiarJugadorActivo()
{
    return;
}
void ModeloCliente::update()
{
    return;
}



/*Network*/
void ModeloCliente::addCommand(Command* command)
{

    //char codigoComando = command->getCodigoComando();
    //char codigoJugador = this->model->getCodigoJugadorActivo();
    //se envia por socket al servidor ambos codigos,

    //Se reciben de socket otros dos codigos

    //El codgoComando que se reciba se tiene que decodificar
    //para saber que comando enviar al model

    //El codigoJugador que se reciba se setea el commando y luego se envia al modelo...

    //EL comando ejecuta en el modelo el metodo apropiado y le pasa el
    //codigo de jugador... el modelo sabe decodificar codigos de jugador


    /* ejemplo aumentarVelocidadEnX(char codigoJugador)
             aumentarVelocidadEnY(char codigoJugador)*/


/*

#define NDECVELX 0x01
#define NDECVELY 0x02
#define NINCVELX 0x03
#define NINCVELY 0x04
#define NSTOPJUG 0x05
#define NACCJUG 0x06
#define NDESJUG 0x07
#define NPATPELO 0x08
#define NRECUPELO 0x09
#define NCAMBJUG 0x0A


*/


    CommandNet* commandNet=nullptr;
    commandNet=this->commands[NINCVELX];






     for( int a = 1; a < 6; a = a + 1 ) {
             commandNet->setearCodigoJugador(6);
     commandNet=this->commands[NINCVELX];
     this->model->addCommand(commandNet);
     this->model->update();


   }

    //this->model->addCommand(commandNet);
    //this->model->update();


}
