#ifndef CAMBIARJUGADOR_H
#define CAMBIARJUGADOR_H

#include "../Controller/Command.h"
#include "../Model/Model.h"

class CambiarJugador : public Command
{
public:
    CambiarJugador(Model* model);
    virtual ~CambiarJugador();
    void execute();
     char getCodigoComando();

protected:

private:
    Model* model;
};

#endif // CAMBIARJUGADOR_H
