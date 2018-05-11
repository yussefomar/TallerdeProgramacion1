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
    this->model->stopJugador(this->getCodigoJugador());
}

char StopJugadorNet::getCodigoComando()
{
    return STOPJUG;
}

