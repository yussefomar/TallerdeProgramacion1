#include "CommandNet.h"
#include "../Model/Model.h"
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
#include <map>
CommandNet::CommandNet()
{
    //ctor
}

CommandNet::~CommandNet()
{
    //dtor
}

 void CommandNet::setCodigoComando(char codigoComando){



 }

 void CommandNet::setearCodigoJugador(char codigoJugador){

     this->codigoJugador=codigoJugador;
 }

