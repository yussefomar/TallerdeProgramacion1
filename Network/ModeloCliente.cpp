#include "ModeloCliente.h"
#include "../Command/CommandNet/DisminuirVelocidadYNet.h"
#include "../Command/CommandNet/AumentarVelocidadYNet.h"
#include "../Command/CommandNet/DisminuirVelocidadXNet.h"
#include "../Command/CommandNet/AumentarVelocidadXNet.h"
#include "../Command/CommandNet/CambiarJugadorNet.h"
#include "../Command/CommandNet/StopJugadorNet.h"
#include "../Command/CommandNet/AcelerarNet.h"
#include "../Command/CommandNet/DesacelerarNet.h"
#include "../Command/CommandNet/PatearPelotaNet.h"
#include "../Command/CommandNet/RecuperarPelotaNet.h"

#define CANTCOMMANDSNET 10
#define ENTIDAD 0
#define EVENTO 1

/*Cuidado... la cantidad de comandos en modelCliente puede y
va a diferir del de controller*/
ModeloCliente::ModeloCliente(Model* model)
{
    this->model = model;
    this->comandos = std::vector<CommandNet*>(CANTCOMMANDSNET);
    this->comandos[DECVELX] = new DisminuirVelocidadXNet(model);
    this->comandos[DECVELY] = new DisminuirVelocidadYNet(model);
    this->comandos[INCVELX] = new AumentarVelocidadXNet(model);
    this->comandos[INCVELY] = new AumentarVelocidadYNet(model);
    this->comandos[CAMBJUG] = new CambiarJugadorNet(model);
    this->comandos[STOPJUG] = new StopJugadorNet(model);
    this->comandos[ACCJUG] = new AcelerarNet(model);
    this->comandos[DESJUG] = new DesacelerarNet(model);

    this->comandos[PATPELO] = new PatearPelotaNet(model);
    this->comandos[RECUPELO] = new RecuperarPelotaNet(model);
}

ModeloCliente::~ModeloCliente()
{
    for(unsigned i = 0; i < CANTCOMMANDSNET; ++i)
    {
        delete this->comandos[i];
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
    /*Zona critica... aun no sabemos reconectarnos*/
    /*Debemos implementar comandosNULL para identificar desconexion*/
    std::string codigoComando;
    CommandNet* comando;
    if(command == nullptr) {
        this->socket.enviarCodigoComandoNulo();
    } else {
        codigoComando.push_back(this->model->getCodigoJugadorActivo());
        codigoComando.push_back(command->getCodigoComando());
        this->socket.enviarCodigoComando(codigoComando);
    }

    unsigned cantidad = this->socket.recibirCantidadCambios();
    for (unsigned i = 0; i < cantidad && this->socket.estaConectado(); ++i) {
        codigoComando = this->socket.recibirCodigoComando();
        comando = this->comandos[codigoComando[EVENTO]];
        comando->setCodigoJugador(codigoComando[ENTIDAD]);
        this->model->addCommand(comando);
    }
}
