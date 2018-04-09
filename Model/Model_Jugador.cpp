#include "Model_Jugador.h"


Jugador::Jugador()
{
    //Initialize the offsets
    mPosX = 950;
    mPosY = 678;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}


void Jugador::move()
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

int Jugador::getPosX()
{
	return mPosX;
}

int Jugador::getPosY()
{
	return mPosY;
}

void Jugador::setPosX(int PosX)
{
	 mPosX= PosX;
}

void Jugador::setPosY(int PosY)
{
	mPosY=PosY ;
}

void Jugador::disminuirVelocidadX()
{
    mVelX -= VELOCIDAD_JUGADOR;;
}

void Jugador::disminuirVelocidadY()
{
	mVelY -= VELOCIDAD_JUGADOR; ;
}

void Jugador::aumentarVelocidadX()
{
	mVelX += VELOCIDAD_JUGADOR; ;
}

void Jugador::aumentarVelocidadY()
{
	mVelY += VELOCIDAD_JUGADOR; ;
}

int Jugador::getVelX()
{
	return mVelX;
}

int Jugador::getVelY()
{
	return mVelY;
}
