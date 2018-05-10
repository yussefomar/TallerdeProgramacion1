#include "../Controller/CambiarJugador.h"

CambiarJugador::CambiarJugador(Model* model)
{
    this->model = model;
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
