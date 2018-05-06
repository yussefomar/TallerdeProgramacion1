#include "ModeloCliente.h"

ModeloCliente::ModeloCliente(Model* model)
{
    this->model = model;
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
    //ejemplo aumentarVelocidadEnX(char codigoJugador)

    this->model->addCommand(command);
}
