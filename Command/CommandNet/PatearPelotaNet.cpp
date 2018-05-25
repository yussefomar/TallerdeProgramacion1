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
    this->model->patearPelota(this->getCodigoJugador());
}

char PatearPelotaNet ::getCodigoComando()
{
    return PATPELO;
}
