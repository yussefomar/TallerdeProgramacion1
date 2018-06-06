#include "../Model/Formacion321.h"

Formacion321::Formacion321()
{
    //ctor
}

Formacion321::~Formacion321()
{
    //dtor
}

void Formacion321::setPosicionInicialLocal(Jugador* jugadores)
{
    int posX;
    int posY;
    int posicionesX[] = { 8,  5,  5,  2,  2,  2, 0};
    int posicionesY[] = { 0, -3,  3,  0, -3,  3, 0};
    int multiplo = -1;
    for(int i = 0; i < CANTJUGADORES; ++i)
    {
        posX = ((ANCHO_NIVEL/2)-(31))+posicionesX[i]*100*multiplo;//cambiar 31 por ancho jugador
        posY = ((ALTO_NIVEL/2)-(31))+posicionesY[i]*100;
        jugadores[i].setPosInitX(posX);
        jugadores[i].setPosInitY(posY);
        jugadores[i].setPosX(posX);
        jugadores[i].setPosY(posY);
    }

}
void Formacion321::setPosicionInicialVisitante(Jugador* jugadores)
{
    int posX;
    int posY;
    int posicionesX[] = { 8,  5,  5,  2,  2,  2, 2};
    int posicionesY[] = { 0, -3,  3,  1, -3,  3, -1};
    int multiplo = 1;
    for(int i = 0; i < CANTJUGADORES; ++i)
    {
        posX = ((ANCHO_NIVEL/2)-(31))+posicionesX[i]*100*multiplo;//cambiar 31 por ancho jugador
        posY = ((ALTO_NIVEL/2)-(31))+posicionesY[i]*100;
        jugadores[i].setPosInitX(posX);
        jugadores[i].setPosInitY(posY);
        jugadores[i].setPosX(posX);
        jugadores[i].setPosY(posY);
        jugadores[i].setDireccion(270);
    }
}

void Formacion321::setPosicionVisitante(Jugador* jugadores)
{
    int posX;
    int posY;
    /*int posicionesX[] = { 8,  4,  4,  5,  -2,  -2, -3};
    int posicionesY[] = { 0, -3,  3,  0, -3,  3, 0};
    */
    int posicionesX[] = { 8,  4,  4,  5,  -3,  -2, -4};
    int posicionesY[] = { 0, -3,  3,  0, -4,  4, 1};

    int multiplo = 1;
    for(int i = 0; i < CANTJUGADORES; ++i)
    {
        posX = ((ANCHO_NIVEL/2)-(31))+posicionesX[i]*100*multiplo;//cambiar 31 por ancho jugador
        posY = ((ALTO_NIVEL/2)-(31))+posicionesY[i]*100;
        jugadores[i].setPosInitX(posX);
        jugadores[i].setPosInitY(posY);
        jugadores[i].setDireccion(270);
    }
}


void Formacion321::setPosicionLocal(Jugador* jugadores)
{
    int posX;
    int posY;
    int posicionesX[] = { 8,  4,  4,  5,  -2,  -2, -3};
    int posicionesY[] = { 0, -3,  3,  0, -3,  3, 0};
    int multiplo = -1;
    for(int i = 0; i < CANTJUGADORES; ++i)
    {
        posX = ((ANCHO_NIVEL/2)-(31))+posicionesX[i]*100*multiplo;//cambiar 31 por ancho jugador
        posY = ((ALTO_NIVEL/2)-(31))+posicionesY[i]*100;
        jugadores[i].setPosInitX(posX);
        jugadores[i].setPosInitY(posY);
    }

}
