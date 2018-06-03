#include "DesacelerarNet.h"

DesacelerarNet::DesacelerarNet(Model* model) : CommandNet(model)
{
}

DesacelerarNet::~DesacelerarNet()
{
    //dtor
}

void DesacelerarNet::execute()
{
    this->model->desacelerar(this->getIdCliente());
}
char DesacelerarNet::getCodigoComando()
{
    return DECVELX;
}

CommandNet* DesacelerarNet::getCopia() {
    return new DesacelerarNet(this->model);
}
