#include "AumentarVelocidadXNet.h"

AumentarVelocidadXNet::AumentarVelocidadXNet(Model* model)
{
    this->model = model;
}

AumentarVelocidadXNet::~AumentarVelocidadXNet()
{
    //dtor
}


void AumentarVelocidadXNet::execute()
{
    this->model->aumentarVelocidadEnX(this->codigoJugador);
}

char AumentarVelocidadXNet::getCodigoComando()
{

    return  NINCVELX ;



}



