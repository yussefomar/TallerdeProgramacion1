#include "CommandNet.h"
#include "../Controller/DisminuirVelocidadY.h"
#include "../Controller/AumentarVelocidadY.h"
#include "../Controller/DisminuirVelocidadX.h"
#include "../Controller/AumentarVelocidadX.h"
#include "../Controller/CambiarJugador.h"
#include "../Controller/StopJugador.h"
#include "../Controller/Acelerar.h"
#include "../Controller/Desacelerar.h"
#include "../Controller/PatearPelota.h"
#include "../Controller/RecuperaPelota.h"

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

