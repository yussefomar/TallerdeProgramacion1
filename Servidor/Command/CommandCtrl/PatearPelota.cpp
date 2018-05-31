#include "PatearPelota.h"

PatearPelota::PatearPelota(Model *model) : CommandCtrl(model)
{
}

PatearPelota::~PatearPelota()
{
    //dtor
}

void PatearPelota ::execute()
{
    if(!this->model->pelotaEnMovimiento())
    {
        this->model->setPelotaEnMovimiento();
    }
    this->model->jugadorActivoPateaPelota();
}

char PatearPelota ::getCodigoComando()
{
    return PATPELO;
}

