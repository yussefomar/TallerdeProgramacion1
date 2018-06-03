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
    if(this->model->pelotaEnMovimiento())
    {
    this->model->aumentarVelocidadEnY(this->getIdCliente());
    }
}

char AumentarVelocidadYNet::getCodigoComando()
{
    return INCVELY;
}

CommandNet* AumentarVelocidadYNet::getCopia() {
    return new AumentarVelocidadYNet(this->model);
}

