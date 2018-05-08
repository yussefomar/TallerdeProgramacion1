#include "CambiarJugadorNet.h"

CambiarJugadorNet::CambiarJugadorNet(Model* model)
{
    this->model = model;
}

CambiarJugadorNet::~CambiarJugadorNet()
{
    //dtor
}

void CambiarJugadorNet::execute()

{
    this->model->jugadorActivoCambia();
}


char CambiarJugadorNet::getCodigoComando() {

return NCAMBJUG;

}
