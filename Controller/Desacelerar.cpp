#include "../Controller/Desacelerar.h"
#include "../Model/Model_Jugador.h"
#include <stdio.h>

Desacelerar::Desacelerar(Model* model)
{
    this->model = model;
}

Desacelerar::~Desacelerar()
{
    //dtor
}

void Desacelerar::execute()
{
    Jugador* jugador = this->model->getJugadorActivo();
    jugador->desacelerar();
}

char Desacelerar::getCodigoComando()
{
    return DESJUG;
}

