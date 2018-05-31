#include "PasarPelota.h"

PasarPelota::PasarPelota(Model *model) : CommandCtrl(model)
{
}

PasarPelota::~PasarPelota()
{
    //dtor
}

void PasarPelota ::execute()
{
    if(!this->model->pelotaEnMovimiento())
    {
        this->model->setPelotaEnMovimiento();
    }
    this->model->jugadorActivoPasaPelota();
}

char PasarPelota ::getCodigoComando()
{
    return PASPELO;
}

