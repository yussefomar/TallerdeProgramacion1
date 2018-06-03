#include "CommandNet.h"

CommandNet::CommandNet(Model* model) : model(model)
{
}

CommandNet::~CommandNet()
{
    //dtor
}

void CommandNet::setIdCliente(char idCliente)
{

    this->idCliente = idCliente;
}

char CommandNet::getIdCliente()
{
    return this->idCliente;
}
