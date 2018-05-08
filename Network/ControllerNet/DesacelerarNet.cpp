#include "DesacelerarNet.h"

DesacelerarNet::DesacelerarNet(Model* model)
{
    this->model = model;
}

DesacelerarNet::~DesacelerarNet()
{
    //dtor
}

void DesacelerarNet::execute() {
    this->model->desacelerar(this->codigoJugador);
}
char DesacelerarNet::getCodigoComando(){

return NDECVELX;

}
