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
// esto va al controlador
void Jugador::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= VELOCIDAD_JUGADOR; break;
            case SDLK_DOWN: mVelY += VELOCIDAD_JUGADOR; break;
            case SDLK_LEFT: mVelX -= VELOCIDAD_JUGADOR; break;
            case SDLK_RIGHT: mVelX += VELOCIDAD_JUGADOR; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += VELOCIDAD_JUGADOR; break;
            case SDLK_DOWN: mVelY -= VELOCIDAD_JUGADOR; break;
            case SDLK_LEFT: mVelX += VELOCIDAD_JUGADOR; break;
            case SDLK_RIGHT: mVelX -= VELOCIDAD_JUGADOR; break;
        }
    }
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
//esto va a la vista
void Jugador::render( int camX, int camY,LTexture * texturaJugador,SDL_Renderer * gRenderer)
{
    //Show the dot relative to the camera
	texturaJugador->render( mPosX - camX, mPosY - camY ,NULL,90.0,NULL,SDL_FLIP_NONE,gRenderer);
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

