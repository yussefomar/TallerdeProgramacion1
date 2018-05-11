#include "StopJugador.h"

StopJugador::StopJugador(Model* model) : CommandCtrl(model)
{
}

StopJugador::~StopJugador()
{

}

void StopJugador::execute()
{
    this->model->jugadorActivoDetener();
}

char StopJugador::getCodigoComando()
{
    return STOPJUG;
}
