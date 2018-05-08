#include "StopJugadorNet.h"

StopJugadorNet::StopJugadorNet(Model* model)
{
    this->model = model;
}

StopJugadorNet::~StopJugadorNet()
{
    //dtor
}



void StopJugadorNet::execute() {
    this->model->stopJugador(this->codigoJugador);
}
char StopJugadorNet::getCodigoComando(){

return NSTOPJUG;

}

