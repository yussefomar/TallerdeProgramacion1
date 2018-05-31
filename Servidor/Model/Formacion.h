#ifndef FORMACION_H
#define FORMACION_H

#include "../Model/Model_Jugador.h"

#define CANTDIVANCHO 12
#define CANTDIVALTO 6
#define CANTJUGADORES 7

class Formacion
{
public:
    Formacion();
    virtual ~Formacion();
    virtual void setPosicionInicialLocal(Jugador* jugadores) = 0;
    virtual void setPosicionLocal(Jugador* jugadores) = 0;
    virtual void setPosicionInicialVisitante(Jugador* jugadores) = 0;
    virtual void setPosicionVisitante(Jugador* jugadores) = 0;
protected:

private:
};

#endif // FORMACION_H
