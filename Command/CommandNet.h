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

    void setCodigoJugador(char codigoJugador);
    char getCodigoJugador();

protected:
    std::queue<char> codigoJugador;
    Model* model;

private:


};

#endif // COMMANDNET_H
