#include "DisminuirVelocidadY.h"

DisminuirVelocidadY::DisminuirVelocidadY(Model* model) : CommandCtrl(model)
{
}

DisminuirVelocidadY::~DisminuirVelocidadY()
{
    //dtor
}

void DisminuirVelocidadY::execute()
{
    this->model->jugadorActivoDisminuyeVelocidadEnY();
}

char DisminuirVelocidadY::getCodigoComando()
{
    return DECVELY;
}
