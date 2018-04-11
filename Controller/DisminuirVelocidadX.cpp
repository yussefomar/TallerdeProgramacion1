#include "DisminuirVelocidadX.h"
#include "Model_Jugador.h"

DisminuirVelocidadX::DisminuirVelocidadX()
{
    //ctor
}

DisminuirVelocidadX::~DisminuirVelocidadX()
{
    //dtor
}

void DisminuirVelocidadX::execute() {
    Jugador* jugador = this->model.getActivePlayer();
    jugador->disminuirVelocidadX();
    jugador->move();
    return;
}

void DisminuirVelocidadX::setModel(Model& model) {
    this->model = model;
}
