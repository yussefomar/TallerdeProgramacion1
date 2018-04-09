#ifndef MODEL_JUGADOR_H_
#define MODEL_JUGADOR_H_
#include <SDL2/SDL.h>
#include "LTexture.h"
//dimension del nivel
const int ANCHO_NIVEL = 2048;
const int ALTO_NIVEL = 1318;

class Jugador
{
    public:
		//The dimensions of the dot
		static const int ANCHO_JUGADOR = 45;
		static const int ALTO_JUGADOR = 45;

		//Maximum axis velocity of the dot
		static const int VELOCIDAD_JUGADOR = 3;

		//Initializes the variables
		Jugador();

		//Moves the dot
		void move();

		//Position accessors
		int getPosX();
		int getPosY();
		//Position accessors
		int getVelX();
		int getVelY();
		void setPosX(int PosX);

        void setPosY(int PosY);

        void disminuirVelocidadX();

        void disminuirVelocidadY();

        void aumentarVelocidadX();

        void aumentarVelocidadY();

    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
};

#endif
