#include "ViewModel.h"
#include <SDL2/SDL.h>

#define CANTVISTASJUG 7

ViewModel::ViewModel(Model* model, SDL_Renderer* gRenderer, SDL_Rect* camara)
{
    this->viewPelota.initialize(model->getPelota(), gRenderer);
    this->viewCancha.initialize(gRenderer);
    this->viewJugadores = new View_Jugador[CANTVISTASJUG];
    this->camara = camara;
    this->gRenderer = gRenderer;

    for(int i = 0; i < CANTVISTASJUG; ++i)
    {
        this->viewJugadores[i].initialize(model->getJugadorNro(i), gRenderer);
    }
}

ViewModel::~ViewModel()
{
    delete[] this->viewJugadores;
}

void ViewModel::render()
{
    //Render background
    this->viewCancha.render(this->camara,this->gRenderer);
    //texturaCancha.render( 0, 0, &camera,0.0,NULL,SDL_FLIP_NONE,gRenderer );

    this->viewPelota.render(this->camara->x, this->camara->y,this->gRenderer);

    //Render objects
//    vistaJugador2.render( this->camera->x, this->camera->y,this->gRenderer);
//
//    vistaJugador3.render( this->camera->x, this->camera->y,this->gRenderer);
//
//    vistaJugador4.render( this->camera->x, this->camera->y,this->gRenderer);
//
//    vistaJugador.render( this->camera->x, this->camera->y,this->gRenderer);

    //Render Jugadores.
    for(int i = 0; i < CANTVISTASJUG; ++i)
    {
        this->viewJugadores[i].render( this->camara->x, this->camara->y,this->gRenderer);
    }
}
