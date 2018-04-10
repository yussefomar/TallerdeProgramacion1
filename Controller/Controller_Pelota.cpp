#include "Controller_Jugador.h"

        Controller_Pelota::Controller_Pelota( Pelota *model,  View_Pelota *view) {
          this->SetModel(model);
          this->SetView(view);
        }
        void Controller_Pelota::SetModel( Pelota *model) {
            this->pelota = model;
        }
        void Controller_Pelota::SetView( View_Pelota *view) {
            this->vista = view;
        }

		//Takes key presses and adjusts the dot's velocity
    void Controller_Jugador::handleEvent( SDL_Event& e ){
    //Jugador jugador = (*this->jugador);
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: (*this->jugador).disminuirVelocidadY(); break;
            case SDLK_DOWN: (*this->jugador).aumentarVelocidadY(); break;
            case SDLK_LEFT: (*this->jugador).disminuirVelocidadX(); break;
            case SDLK_RIGHT: (*this->jugador).aumentarVelocidadX(); break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: (*this->jugador).aumentarVelocidadY(); break;
            case SDLK_DOWN: (*this->jugador).disminuirVelocidadY(); break;
            case SDLK_LEFT: (*this->jugador).aumentarVelocidadX(); break;
            case SDLK_RIGHT: (*this->jugador).disminuirVelocidadX(); break;
        }
    }

		}


