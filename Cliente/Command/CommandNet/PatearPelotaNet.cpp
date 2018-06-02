#include "PatearPelotaNet.h"

PatearPelotaNet::PatearPelotaNet(Model* model) : CommandNet(model)
{
}

PatearPelotaNet::~PatearPelotaNet()
{
    //dtor
}

void PatearPelotaNet ::execute()
{
    if(this->model->pelotaEnMovimiento())
    {
    this->model->patearPelota(this->getIdCliente());
    }
}

char PatearPelotaNet ::getCodigoComando()
{
    return PATPELO;
}
