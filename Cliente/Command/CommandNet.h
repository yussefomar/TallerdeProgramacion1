#ifndef COMMANDNET_H
#define COMMANDNET_H

#include "../Model/Model.h"

#include "Command.h"
#include <queue>


class CommandNet : public Command
{
public:
    CommandNet(Model* model);
    virtual ~CommandNet();

    void setIdCliente(char idCliente);
    char getIdCliente();

protected:
    std::queue<char> idCliente;
    Model* model;

private:


};

#endif // COMMANDNET_H
