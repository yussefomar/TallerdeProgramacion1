#include "AumentarVelocidadX.h"

AumentarVelocidadX::AumentarVelocidadX(Model* model) : CommandCtrl(model)
{
}

AumentarVelocidadX::~AumentarVelocidadX()
{
    //dtor
}

void AumentarVelocidadX::execute()
{
    this->model->jugadorActivoAumentaVelocidadEnX();
}

char AumentarVelocidadX::getCodigoComando()
{
    return  INCVELX ;
}
