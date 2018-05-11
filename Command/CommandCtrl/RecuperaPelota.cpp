#include "RecuperaPelota.h"

RecuperaPelota::RecuperaPelota(Model* model) : CommandCtrl(model)
{
}

RecuperaPelota::~RecuperaPelota()
{
    //dtor
}

void RecuperaPelota ::execute()//La mantiene en su pie
{
    this->model->jugadorActivoRecuperaPelota();
}

char RecuperaPelota ::getCodigoComando()
{
    return RECUPELO;
}
