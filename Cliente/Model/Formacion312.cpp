#include "../Model/Formacion312.h"

Formacion312::Formacion312()
{
    //ctor
}

Formacion312::~Formacion312()
{
    //dtor
}

void Formacion312::setPosicionInicialLocal(Jugador* jugadores)
{
    int posX;
    int posY;
    int posicionesX[] = { 8,  5,  5,  2,  0,  0, 0};
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

void Formacion312::setPosicionInicialVisitante(Jugador* jugadores)
{
    int posX;
    int posY;
    int posicionesX[] = { 8,  5,  5,  2,  0,  0, 2};
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

void Formacion312::setPosicionVisitante(Jugador* jugadores)
{
    int posX;
    int posY;
    int posicionesX[] = { 8,  4,  4,  5,  -3,  3, -2};
    int posicionesY[] = { 0, -3,  3,  0, -3,  3, 0};
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


void Formacion312::setPosicionLocal(Jugador* jugadores)
{
    int posX;
    int posY;
    int posicionesX[] = { 8,  4,  4,  5,  -3,  -3, -2};
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


