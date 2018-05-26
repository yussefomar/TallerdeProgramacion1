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
    this->model->aumentarVelocidadEnX(this->getIdCliente());
}

char AumentarVelocidadXNet::getCodigoComando()
{
    return  INCVELX;
}



