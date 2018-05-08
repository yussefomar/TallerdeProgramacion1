#include "../Controller/RecuperaPelota.h"
#include "../Model/Model_Jugador.h"


RecuperaPelota::RecuperaPelota(Model* model)
{
    this->model=model;
}

RecuperaPelota::~RecuperaPelota()
{
    //dtor
}

void RecuperaPelota ::execute()//La mantiene en su pie
{
    this->model->jugadorActivoRecuperaPelota();
}

char RecuperaPelota ::getCodigoComando(){

return NRECUPELO;

}
