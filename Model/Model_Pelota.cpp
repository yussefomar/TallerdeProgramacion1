#include "Model_Pelota.h"


Pelota::Pelota()
{
    //Initialize the offsets
    mPosX = (ANCHO_NIVEL/2)-6;
    mPosY = (ALTO_NIVEL/2)-6;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Pelota::move()
{
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + ANCHO_JUGADOR > ANCHO_NIVEL) )
    {
        //Move back
        mPosX -= mVelX;
    }

    //Move the dot up or down
    mPosY += mVelY;

    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + ALTO_JUGADOR > ALTO_NIVEL ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}

int Pelota::getPosX()
{
	return mPosX;
}

int Pelota::getPosY()
{
	return mPosY;
}

void Pelota::setPosX(int PosX)
{
	 mPosX= PosX;
}

void Pelota::setPosY(int PosY)
{
	mPosY=PosY ;
}



void Pelota::disminuirVelocidadX()
{
    mVelX -= VELOCIDAD_JUGADOR;;
}

void Pelota::disminuirVelocidadY()
{
	mVelY -= VELOCIDAD_JUGADOR; ;
}

void Pelota::aumentarVelocidadX()
{
	mVelX += VELOCIDAD_JUGADOR; ;
}

void Pelota::aumentarVelocidadY()
{
	mVelY += VELOCIDAD_JUGADOR; ;
}

int Pelota::getVelX()
{
	return mVelX;
}

int Pelota::getVelY()
{
	return mVelY;
}


