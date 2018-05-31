#ifndef AUMENTARVELOCIDADY_H
#define AUMENTARVELOCIDADY_H

#include "CommandCtrl.h"

class AumentarVelocidadY : public CommandCtrl
{
public:
    AumentarVelocidadY(Model* model);
    virtual ~AumentarVelocidadY();
    void execute();
    char getCodigoComando();


protected:

private:
};

#endif // AUMENTARVELOCIDADY_H
