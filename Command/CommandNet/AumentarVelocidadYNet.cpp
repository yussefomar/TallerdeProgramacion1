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
    this->model->aumentarVelocidadEnY(this->getIdCliente());
}

char AumentarVelocidadYNet::getCodigoComando()
{
    return INCVELY;
}

