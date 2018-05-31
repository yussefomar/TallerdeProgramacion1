#ifndef MODEL_EQUIPO_H_
#define MODEL_EQUIPO_H_

#include <SDL2/SDL.h>

#include "../Model/LTexture.h"
#include "../Model/Model_Jugador.h"
#include <iostream>
#include <list>
class Equipo
{
public:

    //Initializes the variables
    Equipo();

    int agregarJugador(Jugador jugador);

private:

    std::list<Jugador> jugadores;
};

#endif
