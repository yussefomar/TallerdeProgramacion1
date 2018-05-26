#include "DisminuirVelocidadXNet.h"

DisminuirVelocidadXNet::DisminuirVelocidadXNet(Model* model) : CommandNet(model)
{
    this->model = model;
}

DisminuirVelocidadXNet::~DisminuirVelocidadXNet()
{
    //dtor
}

void DisminuirVelocidadXNet::execute()
{
    this->model->disminuirVelocidadX(this->getIdCliente());
}

char DisminuirVelocidadXNet::getCodigoComando()
{
    return DECVELX;
}
