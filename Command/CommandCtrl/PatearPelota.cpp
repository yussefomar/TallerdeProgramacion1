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
    this->model->jugadorActivoPateaPelota();
}

char PatearPelota ::getCodigoComando()
{
    return PATPELO;
}

