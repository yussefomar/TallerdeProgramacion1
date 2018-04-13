#include "Controller.h"

#include "DisminuirVelocidadY.h"
#include "AumentarVelocidadY.h"
#include "DisminuirVelocidadX.h"
#include "AumentarVelocidadX.h"

#define CANTCOMMANDS 4


enum IDCommand{DECVELX, DECVELY, INCVELX, INCVELY};

Controller::Controller(Model* model)
{
    this->model = model;
    this->commands = std::vector<Command*>(CANTCOMMANDS);
    this->commands[DECVELX] = new DisminuirVelocidadX(model);
    this->commands[DECVELY] = new DisminuirVelocidadY(model);
    this->commands[INCVELX] = new AumentarVelocidadX(model);
    this->commands[INCVELY] = new AumentarVelocidadY(model);
}

Controller::~Controller()
{
    for(unsigned i = 0; i < CANTCOMMANDS; ++i) {
        delete this->commands[i];
    }
}

Command* Controller::handleEvent(SDL_Event& e)
{
    Command* command = nullptr;
    //Jugador jugador = (*this->jugador);
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:
            //(*this->jugador).disminuirVelocidadY();
            command = this->commands[DECVELY];
            break;
        case SDLK_DOWN:
            //(*this->jugador).aumentarVelocidadY();
            command = this->commands[INCVELY];
            break;
        case SDLK_LEFT:
            //(*this->jugador).disminuirVelocidadX();
            command = this->commands[DECVELX];
            break;
        case SDLK_RIGHT:
            //(*this->jugador).aumentarVelocidadX();
            command = this->commands[INCVELX];
            break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:
            //(*this->jugador).aumentarVelocidadY();
            command = this->commands[INCVELY];
            break;
        case SDLK_DOWN:
            //(*this->jugador).disminuirVelocidadY();
            command = this->commands[DECVELY];
            break;
        case SDLK_LEFT:
            //(*this->jugador).aumentarVelocidadX();
            command = this->commands[INCVELX];
            break;
        case SDLK_RIGHT:
            //(*this->jugador).disminuirVelocidadX();
            command = this->commands[DECVELX];
            break;
        }
    }
    return command;
}
