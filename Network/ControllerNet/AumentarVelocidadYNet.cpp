#include "AumentarVelocidadYNet.h"

AumentarVelocidadYNet::AumentarVelocidadYNet(Model* model)
{
    this->model = model;
}
AumentarVelocidadYNet::~AumentarVelocidadYNet()
{
    //dtor
}

void AumentarVelocidadYNet::execute()
{
    this->model->aumentarVelocidadEnY(this->codigoJugador);
}

char AumentarVelocidadYNet::getCodigoComando(){


return NINCVELY;


}

