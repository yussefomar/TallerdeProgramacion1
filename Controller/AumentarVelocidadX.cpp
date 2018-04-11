#include "AumentarVelocidadX.h"
#include "Model_Jugador.h"

AumentarVelocidadX::AumentarVelocidadX()
{
    //ctor
}

AumentarVelocidadX::~AumentarVelocidadX()
{
    //dtor
}

void AumentarVelocidadX::execute() {
    Jugador* jugador = this->model.getActivePlayer();
    jugador->aumentarVelocidadX();
    jugador->move();
    return;
}

void AumentarVelocidadX::setModel(Model& model) {
    this->model = model;
}
