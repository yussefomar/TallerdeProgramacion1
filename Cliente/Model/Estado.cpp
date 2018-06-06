#include "../Model/Estado.h"

#define VELOCIDAD_JUGADOR 3

Estado::Estado()
{
    //Initialize the offsets
    this->posInitX = 0;
    this->posInitY = 0;
    this->mPosX = this->posInitX;
    this->mPosY = this->posInitY;
    //Initialize the velocity
    this->mVelX = 0;
    this->mVelY = 0;
    this->aceleracion = 1;
    this->acelero=false;
}

Estado::~Estado()
{
    //dtor
}

//Position accessors
int Estado::getPosX()
{
    return this->mPosX;
}
int Estado::getPosY()
{
    return this->mPosY;
}
//Position accessors
int Estado::getVelX()
{
    return this->mVelX;
}
int Estado::getVelY()
{
    return this->mVelY;
}

void Estado::setPosX(int PosX)
{
    this->mPosX = PosX;
}
void Estado::setPosY(int PosY)
{
    this->mPosY = PosY;
}

void Estado::setPosInitX(int posX)
{
    this->posInitX = posX;
}
void Estado::setPosInitY(int posY)
{
    this->posInitY = posY;
}

void Estado::setAceleracion (int ac)
{
    this->aceleracion = ac;
}

void Estado::setVelocidadX(int velx)
{
this->mVelX = velx;

}
void Estado::setVelocidadY(int vely)
{
this->mVelY = vely;

}

void Estado::copiarEstado(Estado* estado)
{
    this->posInitX = estado->posInitX;
    this->posInitY = estado->posInitY;
    this->mPosX = estado->mPosX;
    this->mPosY = estado->mPosY;
    this->mVelX = estado->mVelX;
    this->mVelY = estado->mVelY;
}
void Estado::disminuirVelocidadX()
{
    this->mVelX -=VELOCIDAD_JUGADOR ;
    if(this->mVelX < -VELOCIDAD_JUGADOR)
    {
        this->mVelX = -VELOCIDAD_JUGADOR;
    }
}
void Estado::disminuirVelocidadY()
{
    this->mVelY -=VELOCIDAD_JUGADOR;
    if(this->mVelY < -VELOCIDAD_JUGADOR)
    {
        this->mVelY = -VELOCIDAD_JUGADOR;
    }
}
void Estado::aumentarVelocidadX()
{
    this->mVelX +=VELOCIDAD_JUGADOR;
    if(this->mVelX > VELOCIDAD_JUGADOR)
    {
        this->mVelX = VELOCIDAD_JUGADOR;
    }
}
void Estado::aumentarVelocidadY()
{
    this->mVelY +=VELOCIDAD_JUGADOR;
    if(this->mVelX > VELOCIDAD_JUGADOR)
    {
        this->mVelX = VELOCIDAD_JUGADOR;
    }
}

void Estado::detenerVelocidad()
{
    this->mVelX = 0;
    this->mVelY = 0;
}

void Estado::desacelerar()
{
    this->aceleracion = 1;
    this->acelero=false;
}

int Estado::getAceleracion()
{
    return this->aceleracion;
    this->acelero=true;
}
bool Estado::getAcelero()
{
    return this->acelero;
}
