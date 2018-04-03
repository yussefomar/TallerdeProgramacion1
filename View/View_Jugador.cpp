#include "View_Jugador.h"

        View_Jugador::View_Jugador(){}
        View_Jugador::View_Jugador(const Jugador &model) {
            this->model = model;
        }

        void View_Jugador::SetModel(const Jugador &model) {
            this->model = model;
        }
        void View_Jugador::render( int camX, int camY,LTexture * texturaJugador,SDL_Renderer * gRenderer ){
        }



