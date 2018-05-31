#ifndef AUMENTARVELOCIDADX_H
#define AUMENTARVELOCIDADX_H

#include "CommandCtrl.h"


class AumentarVelocidadX : public CommandCtrl
{
public:
    AumentarVelocidadX(Model* model);
    virtual ~AumentarVelocidadX();
    void execute();
    char getCodigoComando();

protected:

private:
};

#endif // AUMENTARVELOCIDADX_H
