#ifndef VIEW_H
#define VIEW_H

#include "../View/ViewModel.h"
#include "../Model/Model.h"
#include "../Model/Model_Jugador.h"
#include "../Utils/Util_LoggerSubject.h"

class View : public Util_LoggerSubject
{
public:
    View(Model* model);
    virtual ~View();
    void ajustarCamara();
    void render();
    bool inicializar();
    void loadMedia();
    void close();
protected:

private:
    Model* model;
    Jugador* jugadorAnterior;
    ViewModel* viewModel;
    SDL_Rect* camara;
    SDL_Rect camaraStatic;
    SDL_Renderer* gRenderer;
    SDL_Window* window;
    LTexture texturaJugador;
    LTexture texturaSeleccionado;
    LTexture texturaPelota;
    LTexture texturaCancha;
};

#endif // VIEW_H
