#ifndef FORMACION33_H
#define FORMACION33_H

#include "../Model/Formacion.h"


class Formacion33 : public Formacion
{
public:
    Formacion33();
    virtual ~Formacion33();
    void setPosicionInicialLocal(Jugador* jugadores);
    void setPosicionLocal(Jugador* jugadores);
    void setPosicionInicialVisitante(Jugador* jugadores);
    void setPosicionVisitante(Jugador* jugadores);

protected:

private:

};

#endif // FORMACION33_H
