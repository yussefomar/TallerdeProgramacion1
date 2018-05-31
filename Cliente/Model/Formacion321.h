#ifndef FORMACION321_H
#define FORMACION321_H

#include "../Model/Formacion.h"


class Formacion321 : public Formacion
{
public:
    Formacion321();
    virtual ~Formacion321();
    void setPosicionInicialLocal(Jugador* jugadores);
    void setPosicionLocal(Jugador* jugadores);
    void setPosicionInicialVisitante(Jugador* jugadores);
    void setPosicionVisitante(Jugador* jugadores);
protected:

private:
};

#endif // FORMACION321_H
