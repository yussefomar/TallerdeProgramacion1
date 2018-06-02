#include "../View/View_Pelota.h"

View_Pelota::View_Pelota() {}

void View_Pelota::initialize(Pelota *model,SDL_Renderer * gRenderer,LTexture * texturaPelota)
{
//    int frame = 4;
    //  double direccion=90.0;
    this->model = model;
    this->texturaPelota=texturaPelota;
    //Set sprite clips
    gSpriteClips[ 0 ].x =   0;
    gSpriteClips[ 0 ].y =   0;
    gSpriteClips[ 0 ].w =  12;
    gSpriteClips[ 0 ].h = 12;

    gSpriteClips[ 1 ].x =   13;
    gSpriteClips[ 1 ].y =   0;
    gSpriteClips[ 1 ].w =  12;
    gSpriteClips[ 1 ].h = 12;

    gSpriteClips[ 2 ].x =   26;
    gSpriteClips[ 2 ].y =   0;
    gSpriteClips[ 2 ].w =  12;
    gSpriteClips[ 2 ].h = 12;

    gSpriteClips[ 3 ].x =   39;
    gSpriteClips[ 3 ].y =   0;
    gSpriteClips[ 3 ].w =  12;
    gSpriteClips[ 3 ].h = 12;
}

void View_Pelota::SetModel( Pelota * model)
{
    this->model = model;
}
void View_Pelota::render( int camX, int camY,SDL_Renderer * gRenderer )
{
    SDL_Rect* currentClip = &gSpriteClips[frame / 4 ];

    if ((*this->model).getVelX()>0)
    {
        ++frame;
        direccion = 90;
        if ((*this->model).getVelY()>0)
        {
            direccion += 45;
        }
        if ((*this->model).getVelY()<0)
        {
            direccion -= 45;
        }
        if (frame / 4 >= 4)
        {
            frame = 0;
        }
    }

    if ((*this->model).getVelX()<0)
    {
        ++frame;
        direccion = 270;
        if ((*this->model).getVelY()<0)
        {
            direccion += 45;
        }
        if ((*this->model).getVelY()>0)
        {
            direccion -= 45;
        }
        if (frame / 4 >= 4)
        {
            frame = 0;
        }
    }


    if ((((*this->model).getVelX()==0) )&& (((*this->model).getVelY()!=0)))
    {
        ++frame;
        direccion = 90;
        if ((*this->model).getVelY()<0)
        {
            direccion -= 90;
        }
        if ((*this->model).getVelY()>0)
        {
            direccion += 90;
        }
        if (frame / 4 >= 4)
        {
            frame = 0;
        }
    }

    //Show the dot relative to the camera
    this->texturaPelota->render( (*this->model).getPosX() - camX, (*this->model).getPosY() - camY,currentClip,direccion,NULL,SDL_FLIP_NONE,gRenderer);
}


