//#include "View_Seleccionado.h"
//
//View_Pelota::View_Seleccionado()
//{
//}
//
//View_Seleccionado::View_Seleccionado( ,SDL_Renderer * gRenderer)
//{
//    this->model = model;
//    if( !texturaPelota.loadFromFile( "Images/pelota2.png",gRenderer) )
//    {
//        printf( "Failed to load dot texture!\n" );
//        // success = false;
//    }
//    else
//    {
//        //Set sprite clips
//        gSpriteClips[ 0 ].x =   0;
//        gSpriteClips[ 0 ].y =   0;
//        gSpriteClips[ 0 ].w =  12;
//        gSpriteClips[ 0 ].h = 12;
//
//
//    }
//}
//
//void View_Pelota::initialize(Pelota *model,SDL_Renderer * gRenderer)
//{
//    this->model = model;
//    if( !texturaPelota.loadFromFile( "Images/pelota2.png",gRenderer) )
//    {
//        printf( "Failed to load dot texture!\n" );
//        // success = false;
//    }
//    else
//    {
//        //Set sprite clips
//        gSpriteClips[ 0 ].x =   0;
//        gSpriteClips[ 0 ].y =   0;
//        gSpriteClips[ 0 ].w =  12;
//        gSpriteClips[ 0 ].h = 12;
//
//
//    }
//}
//
//void View_Pelota::SetModel( Pelota * model)
//{
//    this->model = model;
//}
//void View_Pelota::render( int camX, int camY,SDL_Renderer * gRenderer )
//{
//    //SDL_Rect* currentClip = &gSpriteClips[frame / 4 ];
//
//    if ((*this->model).getVelX()>0)
//    {
//        ++frame;
//        direccion = 90;
//        if ((*this->model).getVelY()>0)
//        {
//            direccion += 45;
//        }
//        if ((*this->model).getVelY()<0)
//        {
//            direccion -= 45;
//        }
//        if (frame / 4 >= 4)
//        {
//            frame = 0;
//        }
//    }
//
//    if ((*this->model).getVelX()<0)
//    {
//        ++frame;
//        direccion = 270;
//        if ((*this->model).getVelY()<0)
//        {
//            direccion += 45;
//        }
//        if ((*this->model).getVelY()>0)
//        {
//            direccion -= 45;
//        }
//        if (frame / 4 >= 4)
//        {
//            frame = 0;
//        }
//    }
//
//
//    if ((((*this->model).getVelX()==0) )&& (((*this->model).getVelY()!=0)))
//    {
//        ++frame;
//        direccion = 90;
//        if ((*this->model).getVelY()<0)
//        {
//            direccion -= 90;
//        }
//        if ((*this->model).getVelY()>0)
//        {
//            direccion += 90;
//        }
//        if (frame / 4 >= 4)
//        {
//            frame = 0;
//        }
//    }
//
//    //Show the dot relative to the camera
//    this->texturaPelota.render( (*this->model).getPosX() - camX, (*this->model).getPosY() - camY,NULL,direccion,NULL,SDL_FLIP_NONE,gRenderer);
//}
//
//
