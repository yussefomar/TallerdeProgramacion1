#include "../Controller/Acelerar.h"
#include "../Model/Model_Jugador.h"

Acelerar::Acelerar(Model* model)
{
    this->model = model;
}

Acelerar::~Acelerar()
{
    //dtor
}

void Acelerar::execute() {
    Jugador* jugador = this->model->getJugadorActivo();
    jugador->acelerar();
}
