#ifndef COMMANDNULLNET_H
#define COMMANDNULLNET_H

#include "CommandNet.h"


class CommandNullNet : public CommandNet
{
public:
    CommandNullNet(Model* model);
    virtual ~CommandNullNet();
    void execute();
    char getCodigoComando();
    CommandNet* getCopia();

protected:

private:
};

#endif // COMMANDNULLNET_H
