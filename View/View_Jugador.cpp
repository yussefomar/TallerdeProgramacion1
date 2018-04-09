#include "View_Jugador.h"

        View_Jugador::View_Jugador( Jugador *model,SDL_Renderer * gRenderer) {
            this->model = model;
            if( !texturaJugador.loadFromFile( "Images/soccer.png",gRenderer) )
            {
                printf( "Failed to load dot texture!\n" );
               // success = false;
            }
        }

        void View_Jugador::SetModel( Jugador * model) {
            this->model = model;
        }
        void View_Jugador::render( int camX, int camY,SDL_Renderer * gRenderer ){
            //Show the dot relative to the camera
        this->texturaJugador.render( (*this->model).getPosX() - camX, (*this->model).getPosY() - camY ,NULL,90.0,NULL,SDL_FLIP_NONE,gRenderer);
        }




