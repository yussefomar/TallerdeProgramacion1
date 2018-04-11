#include "Controller.h"

Controller::Controller()
{
    this->quit = false;
}

Controller::~Controller()
{
    //dtor
}

void Controller::setModel(Model& model)
{
    this->model = model;
    this->desminuirVelocidadY.setModel(this->model);
    this->aumentarVelocidadX.setModel(this->model);
    this->disminuirVelocidadX.setModel(this->model);
    this->aumentarVelocidadY.setModel(this->model);
}

void Controller::processInput()
{
    while( SDL_PollEvent( &this->event ) != 0 )
    {
        Command* command;
        if( this->event.type == SDL_QUIT )
        {
            quit = true;
            break;
        }
        else
        {
            command = this->handleEvent();
        }
        this->model.addRequest(command);
    }

    return;
}

bool Controller::quitPressed()
{
    return this->quit;
}

Command* Controller::handleEvent()
{
    Command* command;
    if( this->event.type == SDL_KEYDOWN && this->event.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( this->event.key.keysym.sym )
        {
        case SDLK_UP:
            //(*this->jugador).disminuirVelocidadY();
            command = &(this->desminuirVelocidadY);
            break;
        case SDLK_DOWN:
            //(*this->jugador).aumentarVelocidadY();
            command = &(this->aumentarVelocidadY);
            break;
        case SDLK_LEFT:
            //(*this->jugador).disminuirVelocidadX();
            command = &(this->disminuirVelocidadX);
            break;
        case SDLK_RIGHT:
            //(*this->jugador).aumentarVelocidadX();
            command = &(this->aumentarVelocidadX);
            break;
        }
    }
    //If a key was released
    else if( this->event.type == SDL_KEYUP && this->event.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( this->event.key.keysym.sym )
        {
        case SDLK_UP:
            //(*this->jugador).aumentarVelocidadY();
            command = &aumentarVelocidadY;
            break;
        case SDLK_DOWN:
            //(*this->jugador).disminuirVelocidadY();
            command = &desminuirVelocidadY;
            break;
        case SDLK_LEFT:
            //(*this->jugador).aumentarVelocidadX();
            command = &aumentarVelocidadX;
            break;
        case SDLK_RIGHT:
            //(*this->jugador).disminuirVelocidadX();
            command = &disminuirVelocidadX;
            break;
        }
    }
    return command;
}
