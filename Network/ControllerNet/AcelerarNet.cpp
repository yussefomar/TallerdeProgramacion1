#include "AcelerarNet.h"

AcelerarNet::AcelerarNet(Model* model)
{
    this->model = model;
}

AcelerarNet::~AcelerarNet()
{
    //dtor
}


void AcelerarNet::execute() {
    this->model->acelerar(this->codigoJugador);
}

char AcelerarNet::getCodigoComando() {

return NCAMBJUG;

}
