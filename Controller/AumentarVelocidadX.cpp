#include "../Controller/AumentarVelocidadX.h"
#include "../Model/Model_Jugador.h"

AumentarVelocidadX::AumentarVelocidadX(Model* model)
{
    this->model = model;
}

AumentarVelocidadX::~AumentarVelocidadX()
{
    //dtor
}

void AumentarVelocidadX::execute()
{
    Jugador* jugador = this->model->getJugadorActivo();
    jugador->aumentarVelocidadX();
    return;
}

