#ifndef STOPJUGADOR_H
#define STOPJUGADOR_H

#include "CommandCtrl.h"

class StopJugador : public CommandCtrl
{
public:
    StopJugador(Model* model);
    char getCodigoComando();
    virtual ~StopJugador();
    void execute();

protected:

private:
};

#endif // STOPJUGADOR_H
