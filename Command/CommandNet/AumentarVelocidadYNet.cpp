#include "AumentarVelocidadYNet.h"

AumentarVelocidadYNet::AumentarVelocidadYNet(Model* model) : CommandNet(model)
{
}
AumentarVelocidadYNet::~AumentarVelocidadYNet()
{
    //dtor
}

void AumentarVelocidadYNet::execute()
{
    this->model->aumentarVelocidadEnY(this->getCodigoJugador());
}

char AumentarVelocidadYNet::getCodigoComando()
{
    return INCVELY;
}

