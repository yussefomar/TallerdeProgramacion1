#include "../Controller/AumentarVelocidadY.h"
#include "../Model/Model_Jugador.h"

AumentarVelocidadY::AumentarVelocidadY(Model* model)
{
    this->model = model;
}

AumentarVelocidadY::~AumentarVelocidadY()
{
    //dtor
}

void AumentarVelocidadY::execute()
{
    this->model->jugadorActivoAumentaVelocidadEnY();
}

char AumentarVelocidadY::getCodigoComando(){


return NINCVELY;


}

