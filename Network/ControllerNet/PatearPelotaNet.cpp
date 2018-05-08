#include "PatearPelotaNet.h"

PatearPelotaNet::PatearPelotaNet(Model* model)
{
    this->model = model;
}

PatearPelotaNet::~PatearPelotaNet()
{
    //dtor
}

void PatearPelotaNet ::execute()
{
    this->model->patearPelota(this->codigoJugador);
}

 char PatearPelotaNet ::getCodigoComando()
{

   return NPATPELO;

}
