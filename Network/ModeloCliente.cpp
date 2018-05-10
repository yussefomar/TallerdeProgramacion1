#include "ModeloCliente.h"
#include "../Network/ControllerNet/DisminuirVelocidadYNet.h"
#include "../Network/ControllerNet/AumentarVelocidadYNet.h"
#include "../Network/ControllerNet/DisminuirVelocidadXNet.h"
#include "../Network/ControllerNet/AumentarVelocidadXNet.h"
#include "../Network/ControllerNet/CambiarJugadorNet.h"
#include "../Network/ControllerNet/StopJugadorNet.h"
#include "../Network/ControllerNet/AcelerarNet.h"
#include "../Network/ControllerNet/DesacelerarNet.h"
#include "../Network/ControllerNet/PatearPelotaNet.h"
#include "../Network/ControllerNet/RecuperarPelotaNet.h"

#define CANTCOMMANDSNET 10

/*Cuidado... la cantidad de comandos en modelCliente puede y
va a diferir del de controller*/
ModeloCliente::ModeloCliente(Model* model)
{
    this->model = model;
    this->commands = std::vector<CommandNet*>(CANTCOMMANDSNET);
    this->commands[DECVELX] = new DisminuirVelocidadXNet(model);
    this->commands[DECVELY] = new DisminuirVelocidadYNet(model);
    this->commands[INCVELX] = new AumentarVelocidadXNet(model);
    this->commands[INCVELY] = new AumentarVelocidadYNet(model);
    this->commands[CAMBJUG] = new CambiarJugadorNet(model);
    this->commands[STOPJUG] = new StopJugadorNet(model);
    this->commands[ACCJUG] = new AcelerarNet(model);
    this->commands[DESJUG] = new DesacelerarNet(model);

    this->commands[PATPELO] = new PatearPelotaNet(model);
    this->commands[RECUPELO] = new RecuperarPelotaNet(model);
}

ModeloCliente::~ModeloCliente()
{
    for(unsigned i = 0; i < CANTCOMMANDSNET; ++i)
    {
        delete this->commands[i];
    }
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
    /*Esta comprobacion debe desaparecer por algun metodo*/
    if(command == nullptr)
    {
        return;
    }
    /*Recibo codigo comando y lo decodifico*/
    char codigoComando = command->getCodigoComando();
    CommandNet* comando = this->commands[codigoComando];
    /*Seteo al jugador activo en el comando*/
    comando->setCodigoJugador(this->model->getCodigoJugadorActivo());
    /*Agrego comando al modelo sin cambiar nada*/
    this->model->addCommand(comando);
    //Command* comandoNet = this->

}
