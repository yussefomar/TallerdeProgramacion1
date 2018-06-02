#include "../View/View_Cancha.h"

View_Cancha::View_Cancha() {}


void View_Cancha::initialize(SDL_Renderer * gRenderer,LTexture * texturaCancha)
{
    this->texturaCancha=texturaCancha;

}


void View_Cancha::render( SDL_Rect * camara,SDL_Renderer * gRenderer )
{
    this->texturaCancha->render( 0, 0,camara,0.0,NULL,SDL_FLIP_NONE,gRenderer);
}
