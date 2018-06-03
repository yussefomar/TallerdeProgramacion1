#include "AumentarVelocidadXNet.h"

AumentarVelocidadXNet::AumentarVelocidadXNet(Model* model) : CommandNet(model)
{
}

AumentarVelocidadXNet::~AumentarVelocidadXNet()
{
    //dtor
}


void AumentarVelocidadXNet::execute()
{
   if(this->model->pelotaEnMovimiento())
    {
    this->model->aumentarVelocidadEnX(this->getIdCliente());
    }
}

char AumentarVelocidadXNet::getCodigoComando()
{
    return  INCVELX;
}

CommandNet* AumentarVelocidadXNet::getCopia() {
    return new AumentarVelocidadXNet(this->model);
}



