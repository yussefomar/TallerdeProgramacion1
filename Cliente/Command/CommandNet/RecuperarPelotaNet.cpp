#include "RecuperarPelotaNet.h"

RecuperarPelotaNet::RecuperarPelotaNet(Model* model) : CommandNet(model)
{
    //ctor
}

RecuperarPelotaNet::~RecuperarPelotaNet()
{
    //dtor
}


void RecuperarPelotaNet ::execute()//La mantiene en su pie
{
    this->model->recuperaPelota( this->getIdCliente());
}
char RecuperarPelotaNet ::getCodigoComando()
{

    return RECUPELO;

}
