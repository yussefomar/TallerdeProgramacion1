#include "PatearPelotaNet.h"

PatearPelotaNet::PatearPelotaNet(Model* model) : CommandNet(model)
{
    this->model = model;
}

PatearPelotaNet::~PatearPelotaNet()
{
    //dtor
}

void PatearPelotaNet ::execute()
{
    this->model->patearPelota(this->getIdCliente());
}

char PatearPelotaNet ::getCodigoComando()
{
    return PATPELO;
}
