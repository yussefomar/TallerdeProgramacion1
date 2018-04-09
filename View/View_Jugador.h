#ifndef VIEW_JUGADOR_H_
#define VIEW_JUGADOR_H_
#include <SDL2/SDL.h>
#include "../Model/LTexture.h"
#include "../Model/Model_Jugador.h"

class View_Jugador
{
    public:

		View_Jugador( Jugador *model,SDL_Renderer * gRenderer);

        void SetModel( Jugador *model);

		//esto va a la vista
		void render( int camX, int camY,SDL_Renderer * gRenderer );

    private:
        Jugador *model;
        LTexture texturaJugador;
};

#endif
