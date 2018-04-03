#ifndef VIEW_JUGADOR_H_
#define VIEW_JUGADOR_H_
#include <SDL2/SDL.h>
#include "../Model/LTexture.h"
#include "../Model/Model_Jugador.h"

class View_Jugador
{
    public:
        View_Jugador();
		//Initializes the variables
		View_Jugador(const Jugador &model);

        void SetModel(const Jugador &model);

		//esto va a la vista
		void render( int camX, int camY,LTexture * texturaJugador,SDL_Renderer * gRenderer );

    private:
        Jugador model;
};

#endif
