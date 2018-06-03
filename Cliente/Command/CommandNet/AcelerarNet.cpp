#include "AcelerarNet.h"

AcelerarNet::AcelerarNet(Model* model) : CommandNet(model)
{
}

AcelerarNet::~AcelerarNet()
{
    //dtor
}


void AcelerarNet::execute()
{
    this->model->acelerar(this->getIdCliente());
}

char AcelerarNet::getCodigoComando()
{
    return DESJUG;
}

CommandNet* AcelerarNet::getCopia() {
    return new AcelerarNet(this->model);
}
