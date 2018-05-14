#include "../Model/Formacion33.h"

Formacion33::Formacion33()
{

}

Formacion33::~Formacion33()
{
    //dtor
}

void Formacion33::setPosicionInicial(Jugador* jugadores, bool local)
{

    int posX;
    int posY;
    int posicionesX[] = { 8,  4,  4,  5,  0,  0, 0};
    int posicionesY[] = { 0, -3,  3,  0, -3,  3, 0};
    int multiplo = 1;
    if (local) {
    multiplo= -1;
    }
    for(int i = 0; i < CANTJUGADORES; ++i) {
        posX = ((ANCHO_NIVEL/2)-(31))+posicionesX[i]*100*multiplo;//cambiar 31 por ancho jugador
        posY = ((ALTO_NIVEL/2)-(31))+posicionesY[i]*100;
        jugadores[i].setPosInitX(posX);
        jugadores[i].setPosInitY(posY);
        jugadores[i].setPosX(posX);
        jugadores[i].setPosY(posY);
    }
}
