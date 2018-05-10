#include "../Controller/PatearPelota.h"
#include "../Model/Model_Jugador.h"

PatearPelota::PatearPelota(Model *model)
{
    this->model=model;
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

