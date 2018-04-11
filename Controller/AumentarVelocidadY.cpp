#include "AumentarVelocidadY.h"
#include "Model_Jugador.h"

AumentarVelocidadY::AumentarVelocidadY()
{
    //ctor
}

AumentarVelocidadY::~AumentarVelocidadY()
{
    //dtor
}

void AumentarVelocidadY::execute() {
    Jugador* jugador = this->model.getActivePlayer();
    jugador->aumentarVelocidadY();
    jugador->move();
    return;
}

void AumentarVelocidadY::setModel(Model& model) {
    this->model = model;
}
