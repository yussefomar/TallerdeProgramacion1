#include "Acelerar.h"

Acelerar::Acelerar(Model* model) : CommandCtrl(model)
{
}

Acelerar::~Acelerar()
{
    //dtor
}

void Acelerar::execute()
{
    this->model->jugadorActivoAcelera();
}

char Acelerar::getCodigoComando()
{
    return  ACCJUG ;
}
