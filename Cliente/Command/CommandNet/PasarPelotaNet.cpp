#include "PasarPelotaNet.h"

PasarPelotaNet::PasarPelotaNet(Model *model) : CommandNet(model)
{

}

PasarPelotaNet::~PasarPelotaNet()
{
    //dtor
}

void PasarPelotaNet ::execute()
{
    this->model->pasarPelota(this->getIdCliente());
}

char PasarPelotaNet ::getCodigoComando()
{
    return PASPELO;
}

CommandNet* PasarPelotaNet::getCopia() {
    return new PasarPelotaNet(this->model);
}

