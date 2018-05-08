#include "RecuperarPelotaNet.h"

RecuperarPelotaNet::RecuperarPelotaNet(Model* model)
{
    //ctor
}

RecuperarPelotaNet::~RecuperarPelotaNet()
{
    //dtor
}


void RecuperarPelotaNet ::execute()//La mantiene en su pie
{
    this->model->recuperaPelota( this->codigoJugador);
}
char RecuperarPelotaNet ::getCodigoComando(){

return NRECUPELO;

}
