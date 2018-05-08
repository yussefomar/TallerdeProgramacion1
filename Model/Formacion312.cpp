#include "../Model/Formacion312.h"

Formacion312::Formacion312()
{
    //ctor
}

Formacion312::~Formacion312()
{
    //dtor
}

void Formacion312::setPosicionInicial(Jugador* jugadores)
{
    int posX;
    int posY;
    int posicionesX[] = {1, 4, 3, 4, 6, 9, 9};
    int posicionesY[] = {3, 1, 3, 5, 3, 2, 4};

    for(int i = 0; i < CANTJUGADORES; ++i) {
        posX = (posicionesX[i] * ANCHO_NIVEL) / CANTDIVANCHO;
        posY = (posicionesY[i] * ALTO_NIVEL) / CANTDIVALTO;
        jugadores[i].setPosInitX(posX);
        jugadores[i].setPosInitY(posY);
        jugadores[i].setPosX(posX);
        jugadores[i].setPosY(posY);
    }
}
