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
    this->model->acelerar(this->getCodigoJugador());
}

char AcelerarNet::getCodigoComando()
{
    return DESJUG;
}
