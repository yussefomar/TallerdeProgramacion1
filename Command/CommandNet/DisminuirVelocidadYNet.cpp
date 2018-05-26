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
    this->model->disminuirVelocidadY(this->getIdCliente());
}


char DisminuirVelocidadYNet::getCodigoComando()
{
    return DECVELY;
}
