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
    this->model->disminuirVelocidadY(this->getCodigoJugador());
}


char DisminuirVelocidadYNet::getCodigoComando()
{
    return DECVELY;
}
