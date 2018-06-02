#ifndef VIEW_MENSAJES_H_
#define VIEW_MENSAJES_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class View_Mensajes
{
    public:
        View_Mensajes();
        ~View_Mensajes();
        void mostrarMensaje(std::string value, SDL_Renderer* renderer);
        void inicializarMensaje();
        TTF_Font* fontMensaje;
        SDL_Color colorMensaje;

    private:
        std::string mensaje;
};

#endif
