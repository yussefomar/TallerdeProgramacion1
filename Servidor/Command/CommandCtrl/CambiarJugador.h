#ifndef CAMBIARJUGADOR_H
#define CAMBIARJUGADOR_H

#include "CommandCtrl.h"

class CambiarJugador : public CommandCtrl
{
public:
    CambiarJugador(Model* model);
    virtual ~CambiarJugador();
    void execute();
    char getCodigoComando();

protected:

private:
};

#endif // CAMBIARJUGADOR_H
