#include "DisminuirVelocidadYNet.h"

DisminuirVelocidadYNet::DisminuirVelocidadYNet(Model* model) : CommandNet(model)
{
}

DisminuirVelocidadYNet::~DisminuirVelocidadYNet()
{
    //dtor
}


void DisminuirVelocidadYNet::execute()
{
    if(this->model->pelotaEnMovimiento())
    {
    this->model->disminuirVelocidadY(this->getIdCliente());
    }
}


char DisminuirVelocidadYNet::getCodigoComando()
{
    return DECVELY;
}

CommandNet* DisminuirVelocidadYNet::getCopia() {
    return new DisminuirVelocidadYNet(this->model);
}
