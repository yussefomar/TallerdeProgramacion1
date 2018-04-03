#include "Controller_Jugador.h"

        Controller_Jugador::Controller_Jugador(const Jugador &model, const View_Jugador &view) {
          this->SetModel(model);
          this->SetView(view);
        }
        void Controller_Jugador::SetModel(const Jugador &model) {
            this->jugador = model;
        }
        void Controller_Jugador::SetView(const View_Jugador &view) {
            this->vista = view;
        }

		//Takes key presses and adjusts the dot's velocity
		void Controller_Jugador::handleEvent( SDL_Event& e ){
		}


