#ifndef VIEW_PELOTA_H_
#define VIEW_PELOTA_H_

#include <SDL2/SDL.h>

#include "../Model/LTexture.h"
#include "../Model/Model_Pelota.h"
#include "../Utils/Util_LoggerSubject.h"

class View_Pelota : public Util_LoggerSubject
{
public:

    View_Pelota( Pelota * model,SDL_Renderer * gRenderer);
    View_Pelota();

    void SetModel( Pelota * model);
    void initialize(Pelota * model,SDL_Renderer * gRenderer,LTexture * texturaPelota);

    //esto va a la vista
    void render( int camX, int camY,SDL_Renderer * gRenderer );

private:
    Pelota *model;
    LTexture * texturaPelota;
    int frame = 4;
    double direccion;
    SDL_Rect gSpriteClips[ 4 ];
};

#endif
