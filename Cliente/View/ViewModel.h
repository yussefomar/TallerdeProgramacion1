#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "../View/View_Pelota.h"
#include "../View/View_Jugador.h"
#include "../View/View_Cancha.h"
#include "../Model/Model.h"

class ViewModel
{
public:
    ViewModel(Model* model, SDL_Renderer* gRenderer, SDL_Rect* camara,LTexture * texturaCancha,LTexture * texturaPelota,LTexture * texturaJugador,LTexture * texturaSeleccionado);
    virtual ~ViewModel();
    void render();
    bool hayAlgunJugadorActivoEnEspera();
protected:

private:
    View_Pelota viewPelota;
    View_Jugador* viewJugadores;
    View_Jugador* viewJugadoresVisitantes;
    View_Cancha viewCancha;
    SDL_Rect* camara;
    SDL_Renderer* gRenderer;
};

#endif // VIEWMODEL_H
