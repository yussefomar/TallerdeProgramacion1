#ifndef CONTROLLER_JUGADOR_H_
#define CONTROLLER_JUGADOR_H_
#include <SDL2/SDL.h>
#include "../Model/LTexture.h"
#include "../View/View_Jugador.h"
#include "../Model/Model_Jugador.h"

class Controller_Jugador
{
    public:

        Controller_Jugador( const Jugador &model, const View_Jugador &view) ;

        void SetModel( const Jugador &model);

        void SetView(const View_Jugador &view);

		void handleEvent( SDL_Event& e );

    private:

    Jugador jugador;
    View_Jugador vista;
};

#endif
