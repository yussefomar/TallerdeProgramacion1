#include "CambiarJugadorNet.h"

CambiarJugadorNet::CambiarJugadorNet(Model* model) : CommandNet(model)
{
}

CambiarJugadorNet::~CambiarJugadorNet()
{
    //dtor
}

void CambiarJugadorNet::execute()

{
    this->model->cambiarDeJugador(this->getIdCliente());
}


char CambiarJugadorNet::getCodigoComando()
{
    return CAMBJUG;
}
