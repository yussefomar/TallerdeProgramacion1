#include "CambiarJugador.h"

CambiarJugador::CambiarJugador(Model* model) : CommandCtrl(model)
{
}

CambiarJugador::~CambiarJugador()
{
    //dtor
}

void CambiarJugador::execute()
{
    this->model->jugadorActivoCambia();
}

char CambiarJugador::getCodigoComando()
{
    return CAMBJUG;
}
