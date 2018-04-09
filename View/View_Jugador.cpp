#include "View_Jugador.h"

        View_Jugador::View_Jugador( Jugador *model,SDL_Renderer * gRenderer) {
            this->model = model;
            if( !texturaJugador.loadFromFile( "Images/spritejugador.png",gRenderer) )
            {
                printf( "Failed to load dot texture!\n" );
               // success = false;
            }
            else
            {
                //Set sprite clips
                gSpriteClips[ 0 ].x =   0;
                gSpriteClips[ 0 ].y =   128;
                gSpriteClips[ 0 ].w =  63;
                gSpriteClips[ 0 ].h = 63;

                gSpriteClips[ 1 ].x =  64;
                gSpriteClips[ 1 ].y =  128;
                gSpriteClips[ 1 ].w =  63;
                gSpriteClips[ 1 ].h = 63;

                gSpriteClips[ 2 ].x = 128;
                gSpriteClips[ 2 ].y =   128;
                gSpriteClips[ 2 ].w =  63;
                gSpriteClips[ 2 ].h = 63;

                gSpriteClips[ 3 ].x = 192;
                gSpriteClips[ 3 ].y =   128;
                gSpriteClips[ 3 ].w =  63;
                gSpriteClips[ 3 ].h = 63;

            }
        }

        void View_Jugador::SetModel( Jugador * model) {
            this->model = model;
        }
        void View_Jugador::render( int camX, int camY,SDL_Renderer * gRenderer ){
        SDL_Rect* currentClip = &gSpriteClips[frame / 4 ];
        ++frame;
        if (frame / 4 >= 4){
        frame = 0;
        }
            //Show the dot relative to the camera
        this->texturaJugador.render( (*this->model).getPosX() - camX, (*this->model).getPosY() - camY ,currentClip,90.0,NULL,SDL_FLIP_NONE,gRenderer);
        }




