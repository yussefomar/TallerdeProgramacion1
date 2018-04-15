#include "Inactivo.h"

#define VELOCIDAD_JUGADOR 3
#define TOLERANCIA 1

Inactivo::Inactivo()
{
    //ctor
}

Inactivo::~Inactivo()
{
    //dtor
}

void Inactivo::move()
{
    if(this->posInitX - this->mPosX > TOLERANCIA)
    {
        this->mPosX += VELOCIDAD_JUGADOR;
    }
    else if (this->posInitX - this->mPosX < -TOLERANCIA)
    {
        this->mPosX -= VELOCIDAD_JUGADOR;
    }
    else
    {
        this->mVelX = 0;
        this->mPosX = this->posInitX;
    }

    if(this->posInitY - this->mPosY > TOLERANCIA)
    {
        this->mPosY += VELOCIDAD_JUGADOR;
    }
    else if (this->posInitX - this->mPosX < -TOLERANCIA)
    {
        this->mPosY -= VELOCIDAD_JUGADOR;
    }
    else
    {
        this->mVelY = 0;
        this->mPosY = this->posInitY;
    }
}
bool Inactivo::estaActivo()
{
    return false;
}
