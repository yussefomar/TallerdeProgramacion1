#include "Controller.h"

#include "DisminuirVelocidadY.h"
#include "AumentarVelocidadY.h"
#include "DisminuirVelocidadX.h"
#include "AumentarVelocidadX.h"
#include "CambiarJugador.h"

#define CANTCOMMANDS 5


enum IDCommand {DECVELX, DECVELY, INCVELX, INCVELY, CAMBJUG};

Controller::Controller(Model* model)
{
    this->model = model;
    this->commands = std::vector<Command*>(CANTCOMMANDS);
    this->commands[DECVELX] = new DisminuirVelocidadX(model);
    this->commands[DECVELY] = new DisminuirVelocidadY(model);
    this->commands[INCVELX] = new AumentarVelocidadX(model);
    this->commands[INCVELY] = new AumentarVelocidadY(model);
    this->commands[CAMBJUG] = new CambiarJugador(model);
    this->quit = false;
}

Controller::~Controller()
{
    for(unsigned i = 0; i < CANTCOMMANDS; ++i)
    {
        delete this->commands[i];
    }
}

bool Controller::quitPressed()
{
    return this->quit;
}

void Controller::processInput()
{
    while( SDL_PollEvent( &(this->e) ) != 0 )
    {
        if( this->e.type == SDL_QUIT )
        {
            this->quit = true;
        }
        this->model->addCommand(this->handleEvent(this->e));
    }

}

const Uint8 *state = SDL_GetKeyboardState(NULL);



Command* Controller::handleEvent(SDL_Event& e)
{
    Command* command = nullptr;



        if (state[SDL_SCANCODE_E] && state[SDL_SCANCODE_LEFT]) {
        command = this->commands[DECVELX];
        }else if(state[SDL_SCANCODE_E] && state[SDL_SCANCODE_RIGHT]){
         command = this->commands[INCVELX];
        }else if((state[SDL_SCANCODE_E] && state[SDL_SCANCODE_UP])){
            command = this->commands[INCVELY];

        }else if(state[SDL_SCANCODE_E] && state[SDL_SCANCODE_DOWN]){
        command = this->commands[DECVELY];


        }else if( e.type == SDL_KEYUP && e.key.repeat == 0 )/*idea de este if es cuando deje de presionar el E volver a su estado anterior*/
        {
            switch( e.key.keysym.sym )
            {

            case SDLK_UP:
                command = this->commands[DECVELY];
                break;
            case SDLK_DOWN:
                command = this->commands[INCVELY];
                break;
            case SDLK_LEFT:
                command = this->commands[DECVELX];
                break;
            case SDLK_RIGHT:
                command = this->commands[INCVELX];
                break;

            }
        }




        /* NO FUNCIONO PORQUE DETECTA DE A UNA LETRA.
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
        case SDLK_e:
            {


            switch( e.key.keysym.sym )
            {
            case SDLK_UP:
                command = this->commands[DECVELY];
                break;
            case SDLK_DOWN:
                command = this->commands[INCVELY];
                break;
            case SDLK_LEFT:
                command = this->commands[DECVELX];
                break;
            case SDLK_RIGHT:
                command = this->commands[INCVELX];
                break;


            }
            break;
            }
        case SDLK_UP:
            command = this->commands[DECVELY];
            break;
        case SDLK_DOWN:
            command = this->commands[INCVELY];
            break;
        case SDLK_LEFT:
            command = this->commands[DECVELX];
            break;
        case SDLK_RIGHT:
            command = this->commands[INCVELX];
            break;


        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
        case SDLK_e:
            {


            switch( e.key.keysym.sym )
            {
            case SDLK_UP:
                command = this->commands[INCVELY];
                break;
            case SDLK_DOWN:
                command = this->commands[DECVELY];
                break;
            case SDLK_LEFT:
                command = this->commands[INCVELX];
                break;
            case SDLK_RIGHT:
                command = this->commands[DECVELX];
                break;
            }
            break;
            }
        case SDLK_UP:
            command = this->commands[INCVELY];
            break;
        case SDLK_DOWN:
            command = this->commands[DECVELY];
            break;
        case SDLK_LEFT:
            command = this->commands[INCVELX];
            break;
        case SDLK_RIGHT:
            command = this->commands[DECVELX];
            break;

        }

    }



*/

/*ORIGINAL

  if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:
            command = this->commands[DECVELY];
            break;
        case SDLK_DOWN:
            command = this->commands[INCVELY];
            break;
        case SDLK_LEFT:
            command = this->commands[DECVELX];
            break;
        case SDLK_RIGHT:
            command = this->commands[INCVELX];
            break;
        case SDLK_SPACE:
            command = this->commands[CAMBJUG];
            break;

        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:
            command = this->commands[INCVELY];
            break;
        case SDLK_DOWN:
            command = this->commands[DECVELY];
            break;
        case SDLK_LEFT:
            command = this->commands[INCVELX];
            break;
        case SDLK_RIGHT:
            command = this->commands[DECVELX];
            break;

        }
}

*/




    return command;
}
