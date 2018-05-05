#include "../Controller/DisminuirVelocidadY.h"
#include "../Model/Model_Jugador.h"

DisminuirVelocidadY::DisminuirVelocidadY(Model* model)
{
    this->model = model;
}

DisminuirVelocidadY::~DisminuirVelocidadY()
{
    //dtor
}

void DisminuirVelocidadY::execute()
{
    this->model->jugadorActivoDisminuyeVelocidadEnY();
}
