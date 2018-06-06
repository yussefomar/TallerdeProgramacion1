#include "../View/ViewModel.h"
#include <SDL2/SDL.h>

#define CANTVISTASJUG 7

ViewModel::ViewModel(Model* model, SDL_Renderer* gRenderer, SDL_Rect* camara,LTexture * texturaCancha,LTexture * texturaPelota,LTexture * texturaJugador,LTexture * texturaSeleccionado)
{

    this->viewPelota.initialize(model->getPelota(), gRenderer,texturaPelota);
    this->viewCancha.initialize(gRenderer,texturaCancha);
    this->viewJugadores = new View_Jugador[CANTVISTASJUG];
    this->viewJugadoresVisitantes = new View_Jugador[CANTVISTASJUG];
    this->camara = camara;
    this->gRenderer = gRenderer;

    for(int i = 0; i < CANTVISTASJUG; ++i)
    {
        this->viewJugadores[i].initialize(model->getJugadorNro(i), gRenderer,texturaJugador,texturaSeleccionado);
        this->viewJugadoresVisitantes[i].initialize(model->getJugadorVisitanteNro(i), gRenderer,texturaJugador,texturaSeleccionado);
    }
}

ViewModel::~ViewModel()
{
    delete[] this->viewJugadores;
    delete[] this->viewJugadoresVisitantes;
}

void ViewModel::render()
{
    this->viewCancha.render(this->camara,this->gRenderer);
    this->viewPelota.render(this->camara->x, this->camara->y,this->gRenderer);


    /*if(this->hayAlgunJugadorActivoEnEspera()==true)
    {

        for(int i = 0; i < CANTVISTASJUG; ++i)
        {


            this->viewJugadores[i].renderEnEspera( this->camara->x, this->camara->y,this->gRenderer);
            this->viewJugadoresVisitantes[i].renderEnEspera( this->camara->x, this->camara->y,this->gRenderer);
        }
    }
    else
    {*/

        for(int i = 0; i < CANTVISTASJUG; ++i)
        {

            this->viewJugadores[i].render( this->camara->x, this->camara->y,this->gRenderer);
            this->viewJugadoresVisitantes[i].render( this->camara->x, this->camara->y,this->gRenderer);

        }

   // }
}

bool ViewModel::hayAlgunJugadorActivoEnEspera()
{

    bool espera=false;
    for(int i = 0; i < CANTVISTASJUG; ++i)
    {

        //bool jugadorActivoEnEspera=this->viewJugadores[i].enEspera;
        if(this->viewJugadores[i].enEspera())
        {
            espera= true;

        }

    }

    return espera;

}


