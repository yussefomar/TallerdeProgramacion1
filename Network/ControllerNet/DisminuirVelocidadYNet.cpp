#include "DisminuirVelocidadYNet.h"

DisminuirVelocidadYNet::DisminuirVelocidadYNet(Model* model)
{
    this->model = model;
}

DisminuirVelocidadYNet::~DisminuirVelocidadYNet()
{
    //dtor
}


void DisminuirVelocidadYNet::execute()
{
    this->model->disminuirVelocidadY(this->codigoJugador);
}


char DisminuirVelocidadYNet::getCodigoComando() {

return NDECVELY;


}
