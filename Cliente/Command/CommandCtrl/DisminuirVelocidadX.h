#ifndef DISMINUIRVELOCIDADX_H
#define DISMINUIRVELOCIDADX_H

#include "CommandCtrl.h"

class DisminuirVelocidadX : public CommandCtrl
{
public:
    DisminuirVelocidadX(Model* model);
    virtual ~DisminuirVelocidadX();
    void execute();
    char getCodigoComando();

protected:

private:
};

#endif // DISMINUIRVELOCIDADX_H
