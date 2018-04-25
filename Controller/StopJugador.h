#ifndef STOPJUGADOR_H
#define STOPJUGADOR_H

#include "../Controller/Command.h"
#include "../Model/Model.h"

class StopJugador : public Command
{
public:
    StopJugador(Model* model);
    virtual ~StopJugador();
    void execute();


protected:

private:
    Model* model;
};

#endif // STOPJUGADOR_H
