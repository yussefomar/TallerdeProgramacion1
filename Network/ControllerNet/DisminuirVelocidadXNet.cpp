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
    this->model->disminuirVelocidadX(this->getCodigoJugador());
}

char DisminuirVelocidadXNet::getCodigoComando()
{
    return DECVELX;
}
