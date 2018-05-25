#include "ModeloCliente.h"
#include "DisminuirVelocidadYNet.h"
#include "AumentarVelocidadYNet.h"
#include "DisminuirVelocidadXNet.h"
#include "AumentarVelocidadXNet.h"
#include "CambiarJugadorNet.h"
#include "StopJugadorNet.h"
#include "AcelerarNet.h"
#include "DesacelerarNet.h"
#include "PatearPelotaNet.h"
#include "RecuperarPelotaNet.h"
#include "CommandNullNet.h"

#define CANTCOMMANDSNET 11
#define ENTIDAD 0
#define EVENTO 1

#define ENVIAR 0
#define RECIBIR 1
#define EJECUTAR 2

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
    this->comandos[COMMNULL]  = new CommandNullNet(model);
    this->tareaAEjecutar = 0;
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
/*Network*/

void ModeloCliente::update()
{
    this->tareaAEjecutar = this->tareaAEjecutar % 3;
    if(this->tareaAEjecutar == ENVIAR)
    {
        this->tareaAEjecutar += this->enviarUnComando();
        this->model->moverJuego();
    }
    else if (this->tareaAEjecutar == RECIBIR)
    {
        this->tareaAEjecutar += this->recibirUnComando();
        this->model->moverJuego();
    }
    else if (this->tareaAEjecutar == EJECUTAR)
    {
        this->tareaAEjecutar += this->ejecutarUnComando();
    }
}



void ModeloCliente::agregarCambio(Command* cambio)
{
    if(cambio->getCodigoComando() == COMMNULL)
        return;
    std::string codigoComando;
    codigoComando.push_back(this->model->getCodigoJugadorActivo());
    codigoComando.push_back(cambio->getCodigoComando());
    this->codigosAEnviar.push(codigoComando);
}


unsigned ModeloCliente::enviarUnComando()
{
    if(this->codigosAEnviar.empty())
    {
        this->socket.enviarByte(COMMNULL);
        return 1;
    }

    std::string codigo = this->codigosAEnviar.front();
    this->codigosAEnviar.pop();
    this->socket.enviarCodigoComando(codigo);

    return 1;
}

unsigned ModeloCliente::recibirUnComando()
{
    std::string codigoRecibido = this->socket.recibirCodigoComando();
    CommandNet* comando = this->comandos[codigoRecibido[EVENTO]];
    comando->setCodigoJugador(codigoRecibido[ENTIDAD]);
    this->model->agregarCambio(comando);
    return 1;
}

unsigned ModeloCliente::ejecutarUnComando()
{
    this->model->update();
    return 1;
}

void ModeloCliente::enviarMensajeLogin()
{
    return;
}

char ModeloCliente::recibirMensajeLogin()
{
    char byte;
    return byte;
}
