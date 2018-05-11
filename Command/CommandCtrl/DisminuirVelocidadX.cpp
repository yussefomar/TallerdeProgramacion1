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
    this->model->jugadorActivoDisminuyeVelocidadEnX();
}

char DisminuirVelocidadX::getCodigoComando()
{
    return DECVELX;
}
