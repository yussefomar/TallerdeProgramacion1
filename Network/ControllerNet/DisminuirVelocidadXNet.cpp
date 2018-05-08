#include "DisminuirVelocidadXNet.h"

DisminuirVelocidadXNet::DisminuirVelocidadXNet(Model* model)
{
    this->model = model;
}

DisminuirVelocidadXNet::~DisminuirVelocidadXNet()
{
    //dtor
}

void DisminuirVelocidadXNet::execute()
{
    this->model->disminuirVelocidadX(this->codigoJugador);
}

char DisminuirVelocidadXNet::getCodigoComando() {
 return NDECVELX;


 }
