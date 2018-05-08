#ifndef AUMENTARVELOCIDADY_H
#define AUMENTARVELOCIDADY_H

#include "../Controller/Command.h"
#include "../Model/Model.h"

class AumentarVelocidadY : public Command
{
public:
    AumentarVelocidadY(Model* model);
    virtual ~AumentarVelocidadY();
    void execute();
     char getCodigoComando();


protected:

private:
    Model* model;
};

#endif // AUMENTARVELOCIDADY_H
