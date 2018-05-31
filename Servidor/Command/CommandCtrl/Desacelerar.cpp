#include "Desacelerar.h"

Desacelerar::Desacelerar(Model* model) : CommandCtrl(model)
{
}

Desacelerar::~Desacelerar()
{
    //dtor
}

void Desacelerar::execute()
{
    this->model->jugadorActivoDesacelera();
}

char Desacelerar::getCodigoComando()
{
    return DESJUG;
}

