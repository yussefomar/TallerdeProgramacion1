#include "DisminuirVelocidadX.h"

DisminuirVelocidadX::DisminuirVelocidadX(Model* model) : CommandCtrl(model)
{
}

DisminuirVelocidadX::~DisminuirVelocidadX()
{
    //dtor
}

void DisminuirVelocidadX::execute()
{
    if(this->model->pelotaEnMovimiento())
    {
        this->model->jugadorActivoDisminuyeVelocidadEnX();
    }
}

char DisminuirVelocidadX::getCodigoComando()
{
    return DECVELX;
}
