#ifndef FORMACION312_H
#define FORMACION312_H

#include "../Model/Formacion.h"


class Formacion312 : public Formacion
{
public:
    Formacion312();
    virtual ~Formacion312();
    void setPosicionInicialLocal(Jugador* jugadores);
    void setPosicionLocal(Jugador* jugadores);
    void setPosicionInicialVisitante(Jugador* jugadores);
    void setPosicionVisitante(Jugador* jugadores);

protected:

private:
};

#endif // FORMACION312_H
