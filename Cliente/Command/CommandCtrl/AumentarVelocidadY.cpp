#include "AumentarVelocidadY.h"

AumentarVelocidadY::AumentarVelocidadY(Model* model) : CommandCtrl(model)
{
}

AumentarVelocidadY::~AumentarVelocidadY()
{
    //dtor
}

void AumentarVelocidadY::execute()
{
    if(this->model->pelotaEnMovimiento())
    {
        this->model->jugadorActivoAumentaVelocidadEnY();
    }
}

char AumentarVelocidadY::getCodigoComando()
{
    return INCVELY;
}

