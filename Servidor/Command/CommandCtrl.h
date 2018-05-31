#ifndef COMMANDCTRL_H
#define COMMANDCTRL_H

#include "Command.h"
#include "Model.h"


class CommandCtrl : public Command
{
public:
    CommandCtrl(Model* model);
    virtual ~CommandCtrl();

protected:
    Model* model;

private:
};

#endif // COMMANDCTRL_H
