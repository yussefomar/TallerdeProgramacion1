#ifndef COMMANDNULL_H
#define COMMANDNULL_H

#include "CommandCtrl.h"

class CommandNull : public CommandCtrl
{
public:
    CommandNull(Model* model);
    virtual ~CommandNull();
    void execute();
    char getCodigoComando();

protected:

private:
};

#endif // COMMANDNULL_H
