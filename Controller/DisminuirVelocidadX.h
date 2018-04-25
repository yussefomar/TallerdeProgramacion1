#ifndef DISMINUIRVELOCIDADX_H
#define DISMINUIRVELOCIDADX_H

#include "../Controller/Command.h"
#include "../Model/Model.h"


class DisminuirVelocidadX : public Command
{
public:
    DisminuirVelocidadX(Model* model);
    virtual ~DisminuirVelocidadX();
    void execute();

protected:

private:
    Model* model;
};

#endif // DISMINUIRVELOCIDADX_H
