#ifndef DISMINUIRVELOCIDADY_H
#define DISMINUIRVELOCIDADY_H

#include "CommandCtrl.h"

class DisminuirVelocidadY : public CommandCtrl
{
public:
    DisminuirVelocidadY(Model* model);
    char getCodigoComando();
    virtual ~DisminuirVelocidadY();
    void execute();

protected:

private:
};

#endif // DISMINUIRVELOCIDADY_H
