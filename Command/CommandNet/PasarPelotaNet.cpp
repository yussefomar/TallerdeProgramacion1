#include "PasarPelotaNet.h"

PasarPelotaNet::PasarPelotaNet(Model *model) : CommandCtrl(model)
{
}

PasarPelotaNet::~PasarPelotaNet()
{
    //dtor
}

void PasarPelotaNet ::execute()
{
    if(!this->model->pelotaEnMovimiento())
    {
        this->model->setPelotaEnMovimiento();
    }
    this->model->jugadorActivoPasaPelota();
}

char PasarPelotaNet ::getCodigoComando()
{
    return PASPELO;
}

