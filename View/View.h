#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "View_Jugador.h"
#include "View_Pelota.h"
#include "Observer.h"
#include "Model.h"

class View : public Observer
{
    public:
        View();
        virtual ~View();
        void render();
        void update();
        void setModel(Model& model);


    protected:

    private:
        unsigned short logLevel;

        //The camera area
        SDL_Rect camera;
        //The window we'll be rendering to
        SDL_Window* window;
        //The window renderer
        SDL_Renderer* gRenderer;

        LTexture texturaCancha;

        Model model;

        bool inicializar();
        bool loadMedia();
        void close();
        //solo una vista por el momento.
        View_Jugador viewJugador;

};

#endif // VIEW_H
