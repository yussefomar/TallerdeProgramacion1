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
    if(this->model->pelotaEnMovimiento())
    {
        this->model->jugadorActivoDisminuyeVelocidadEnY();
    }
}

char DisminuirVelocidadY::getCodigoComando()
{
    return DECVELY;
}
