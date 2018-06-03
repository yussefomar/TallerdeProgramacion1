#include "DisminuirVelocidadXNet.h"

DisminuirVelocidadXNet::DisminuirVelocidadXNet(Model* model) : CommandNet(model)
{
}

DisminuirVelocidadXNet::~DisminuirVelocidadXNet()
{
    //dtor
}

void DisminuirVelocidadXNet::execute()
{
    if(this->model->pelotaEnMovimiento())
    {
    this->model->disminuirVelocidadX(this->getIdCliente());
    }
}

char DisminuirVelocidadXNet::getCodigoComando()
{
    return DECVELX;
}

CommandNet* DisminuirVelocidadXNet::getCopia() {
    return new DisminuirVelocidadXNet(this->model);
}
