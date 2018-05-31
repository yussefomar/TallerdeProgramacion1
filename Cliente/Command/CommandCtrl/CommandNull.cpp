#include "CommandNull.h"

CommandNull::CommandNull(Model* model) : CommandCtrl(model)
{
    //ctor
}

CommandNull::~CommandNull()
{
    //dtor
}

void CommandNull::execute()
{
    return;
}

char CommandNull::getCodigoComando()
{
    return COMMNULL;
}
