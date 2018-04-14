#include "Model_Jugador.h"


Jugador::Jugador()
{
    //Initialize the offsets
    mPosX = 950;
    mPosY = 678;
    casaca = true;

    mCollider.x = mPosX;
    mCollider.y = mPosY;
    mCollider.w = ANCHO_JUGADOR;
    mCollider.h = ALTO_JUGADOR;
    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}


void Jugador::move()
{
    //Move the dot left or right
    mPosX += mVelX;
	mCollider.x = mPosX;
    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + ANCHO_JUGADOR > ANCHO_NIVEL) )
    {
        //Move back
        mPosX -= mVelX;
    }

    //Move the dot up or down
    mPosY += mVelY;
	mCollider.y = mPosY;
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

void Jugador::setCasacaAlternativa()
{
	casaca=false ;
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
bool Jugador::casacaPrincipal()
{
	return casaca;
}

void Jugador::stop()
{
	mVelY = 0;
	mVelX = 0;
}
bool Jugador::collide(SDL_Rect * camara)
{
 //The sides of the rectangles
    int leftCam, leftJugador;
    int rightCam, rightJugador;
    int topCam, topJugador;
    int bottomCam, bottomJugador;

    //Calculate the sides of rect A
    leftCam = camara->x;

    rightCam = camara->x + camara->w;

    topCam = camara->y;

    bottomCam = camara->y + camara->h;

    //Calculate the sides of rect B
    leftJugador = this->mCollider.x;
    printf("leftcam %i - ",leftCam);
    printf("leftJugador - %i\n",leftJugador);
    rightJugador = this->mCollider.x + this->mCollider.w;
    printf("rightCam %i",rightCam);
     printf("rightJugador %i\n",rightJugador);
    topJugador = this->mCollider.y;
    printf("topCam %i",topCam);
    printf("topJugador %i\n",topJugador);
    bottomJugador = this->mCollider.y + this->mCollider.h;
    printf("bottomCam %i",topCam);
    printf("bottomJugador %i\n\n\n",bottomJugador);


    //If any of the sides from A are outside of B

     if( bottomCam <= topJugador )
    {
        return false;
    }

    if( topCam >= bottomJugador )
    {
        return false;
    }

    if( rightCam <= leftJugador )
    {
        return false;
    }

    if( leftCam >= rightJugador )
    {
        return false;
    }
    return true;
}
