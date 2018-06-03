#include "DesconexionAjena.h"

DesconexionAjena::DesconexionAjena(Model* model) : CommandNet(model)
{
    //ctor
}

DesconexionAjena::~DesconexionAjena()
{
    //dtor
}

char DesconexionAjena::getCodigoComando() {
    return DESCJUG;
}

void DesconexionAjena::execute() {
    this->model->desconectarCliente(this->getIdCliente());
}
CommandNet* DesconexionAjena::getCopia() {
    return new DesconexionAjena(this->model);
}


