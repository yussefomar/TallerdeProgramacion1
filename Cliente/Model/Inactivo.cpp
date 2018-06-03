#include "../Model/Inactivo.h"

#define VELOCIDAD_JUGADOR 3
#define TOLERANCIA 3

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
    if (posInitX>mPosX)
    {
        this->mVelX=VELOCIDAD_JUGADOR;
        this->mPosX += this->mVelX;
    }
    if (posInitX<mPosX)
    {
        this->mVelX=-VELOCIDAD_JUGADOR;
        this->mPosX += this->mVelX;
    }

    if (posInitY>mPosY)
    {
        this->mVelY=VELOCIDAD_JUGADOR;
        this->mPosY += this->mVelY;
    }
    if (posInitY<mPosY)
    {
        this->mVelY=-VELOCIDAD_JUGADOR;
        this->mPosY += this->mVelY;
    }
    if ((mPosX >= posInitX - TOLERANCIA) &&  (mPosX <= posInitX + TOLERANCIA))
    {
        this->mVelX=0;
    }
    if (( mPosY >= posInitY - TOLERANCIA) && (mPosY <= posInitY + TOLERANCIA))
    {
        this->mVelY=0;
    }

}
bool Inactivo::estaActivo()
{
    return false;
}

void Inactivo::acelerar()
{
    return;
}
