#include "../View/View_Mensajes.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

SDL_Texture* SurfaceToTexture( SDL_Surface* surf, SDL_Renderer* renderer );

View_Mensajes::View_Mensajes() {
    inicializarMensaje();
}

View_Mensajes::~View_Mensajes()
{
    TTF_CloseFont( this->fontMensaje );
    //Quit SDL_ttf
    TTF_Quit();
}

void View_Mensajes::inicializarMensaje()
{
    if ( TTF_Init() == -1 )
    {
        //std::cout << " Falla al inicializar el TTF : " << SDL_GetError() << std::endl;
        return;
    }
    std::string fontNombreMensajes = "Images/Roboto-Regular.ttf";
    this->fontMensaje = TTF_OpenFont( fontNombreMensajes.c_str(), 25 );;
    this->colorMensaje = { 0, 0, 0, 255 }; //red
}

void View_Mensajes::mostrarMensaje(std::string value, SDL_Renderer* renderer)
{
    SDL_Rect mensajeRect;
    SDL_Surface* mensaje = TTF_RenderText_Solid( this->fontMensaje, value.c_str(), this->colorMensaje );
    SDL_Texture* mensajeTexture = SurfaceToTexture( mensaje, renderer );
    SDL_QueryTexture( mensajeTexture, NULL, NULL, &mensajeRect.w, &mensajeRect.h );
    mensajeRect.x = 50; mensajeRect.y = 550;

    SDL_RenderCopy( renderer, mensajeTexture, nullptr, &mensajeRect );
}

// Convert an SDL_Surface to SDL_Texture. We've done this before, so I'll keep it short
SDL_Texture* SurfaceToTexture( SDL_Surface* surf, SDL_Renderer* renderer )
{
    SDL_Texture* text;

    text = SDL_CreateTextureFromSurface( renderer, surf );

    SDL_FreeSurface( surf );

    return text;
}
