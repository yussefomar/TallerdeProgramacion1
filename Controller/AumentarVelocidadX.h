#ifndef AUMENTARVELOCIDADX_H
#define AUMENTARVELOCIDADX_H

#include "../Controller/Command.h"
#include "../Model/Model.h"


class AumentarVelocidadX : public Command
{
public:
    AumentarVelocidadX(Model* model);
    virtual ~AumentarVelocidadX();
    void execute();
     char getCodigoComando();

protected:

private:
    Model* model;
};

#endif // AUMENTARVELOCIDADX_H
