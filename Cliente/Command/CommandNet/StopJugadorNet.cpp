#include "StopJugadorNet.h"

StopJugadorNet::StopJugadorNet(Model* model) : CommandNet(model)
{
}

StopJugadorNet::~StopJugadorNet()
{
    //dtor
}



void StopJugadorNet::execute()
{
    this->model->stopJugador(this->getIdCliente());
}

char StopJugadorNet::getCodigoComando()
{
    return STOPJUG;
}

CommandNet* StopJugadorNet::getCopia() {
    return new StopJugadorNet(this->model);
}
