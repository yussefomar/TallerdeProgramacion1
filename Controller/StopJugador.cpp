#include "../Controller/StopJugador.h"
#include "../Model/Model_Jugador.h"

StopJugador::StopJugador(Model* model)
{
    this->model = model;
}

StopJugador::~StopJugador()
{

}

void StopJugador::execute() {
    this->model->jugadorActivoDetener();
}
