#include "CommandNet.h"

CommandNet::CommandNet(Model* model) : model(model)
{
}

CommandNet::~CommandNet()
{
    //dtor
}

 void CommandNet::setCodigoJugador(char codigoJugador){

     this->codigoJugador.push(codigoJugador);
 }

 char CommandNet::getCodigoJugador() {
    char codigo = this->codigoJugador.front();
    this->codigoJugador.pop();
    return codigo;
 }

