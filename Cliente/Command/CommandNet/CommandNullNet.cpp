#include "CommandNullNet.h"

CommandNullNet::CommandNullNet(Model* model) : CommandNet(model)
{
    //ctor
}

CommandNullNet::~CommandNullNet()
{
    //dtor
}

void CommandNullNet::execute()
{
    return;
}

char CommandNullNet::getCodigoComando()
{
    return COMMNULL;
}
