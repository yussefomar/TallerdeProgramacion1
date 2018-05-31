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

    this->idCliente.push(idCliente);
}

char CommandNet::getIdCliente()
{
    char id = this->idCliente.front();
    this->idCliente.pop();
    return id;
}

