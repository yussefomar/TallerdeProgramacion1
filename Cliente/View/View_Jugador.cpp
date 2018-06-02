#include "../View/View_Jugador.h"

#include <sstream>

View_Jugador::View_Jugador() {}

void View_Jugador::initialize(Jugador *model,SDL_Renderer * gRenderer,LTexture * texturaJugador,LTexture * texturaSeleccionado)
{
    this->texturaJugador=texturaJugador;
    this->texturaSeleccionado=texturaSeleccionado;
    this->model = model;
    texturaSeleccionado->setAlpha(200);
    texturaSeleccionado->setColor(150,100,150);
    int offset = 0;
    if (!model->casacaPrincipal())
    {
        offset = 256;
    }
    //Set sprite clips
    gSpriteClips[ 0 ].x =   offset+0; //si sumo 256 en X tengo la otra camiseta
    gSpriteClips[ 0 ].y =   128;
    gSpriteClips[ 0 ].w =  62;
    gSpriteClips[ 0 ].h = 62;

    gSpriteClips[ 1 ].x =  offset+64;
    gSpriteClips[ 1 ].y =  128;
    gSpriteClips[ 1 ].w =  62;
    gSpriteClips[ 1 ].h = 62;

    gSpriteClips[ 2 ].x = offset+128;
    gSpriteClips[ 2 ].y =   128;
    gSpriteClips[ 2 ].w =  62;
    gSpriteClips[ 2 ].h = 62;

    gSpriteClips[ 3 ].x = offset+192;
    gSpriteClips[ 3 ].y =   128;
    gSpriteClips[ 3 ].w =  62;
    gSpriteClips[ 3 ].h = 62;
    //correr

    gSpriteClips[ 4].x =   offset+0;
    gSpriteClips[ 4 ].y =   192;
    gSpriteClips[ 4 ].w =  62;
    gSpriteClips[ 4 ].h = 62;

    gSpriteClips[ 5 ].x =  offset+64;
    gSpriteClips[ 5 ].y =  192;
    gSpriteClips[ 5 ].w =  62;
    gSpriteClips[ 5 ].h = 62;

    gSpriteClips[ 6 ].x = offset+128;
    gSpriteClips[ 6 ].y =   192;
    gSpriteClips[ 6 ].w =  62;
    gSpriteClips[ 6 ].h = 62;

    gSpriteClips[ 7 ].x = offset+192;
    gSpriteClips[ 7 ].y =   192;
    gSpriteClips[ 7 ].w =  62;
    gSpriteClips[ 7 ].h = 62;




    //patear



    gSpriteClips[ 8 ].x =  offset+0;
    gSpriteClips[  8].y =  385;
    gSpriteClips[ 8].w =  62;
    gSpriteClips[ 8 ].h = 62;



    //nadar o cabecear , sin uso por ahora
    gSpriteClips[ 9 ].x =   offset+0; //si sumo 256 en X tengo la otra camiseta
    gSpriteClips[ 9].y =   256;
    gSpriteClips[ 9 ].w =  62;
    gSpriteClips[ 9 ].h = 62;

    gSpriteClips[ 10 ].x =  offset+64;
    gSpriteClips[  10].y =  256;
    gSpriteClips[ 10 ].w =  62;
    gSpriteClips[ 10 ].h = 62;

    gSpriteClips[ 11 ].x = offset+128;
    gSpriteClips[ 12 ].y =   256;
    gSpriteClips[ 12 ].w =  62;
    gSpriteClips[ 12 ].h = 62;

    gSpriteClips[ 13 ].x = offset+192;
    gSpriteClips[ 13 ].y =   256;
    gSpriteClips[ 13 ].w =  62;
    gSpriteClips[ 13 ].h = 62;





}

void View_Jugador::SetModel( Jugador * model)
{
    this->model = model;
}
/*void View_Jugador::render( int camX, int camY,SDL_Renderer * gRenderer )
{


    SDL_Rect* currentClip = &gSpriteClips[frame / 4 ];
    int acelera=this->model->getAcelero();
    int velocidadX=this->model->getVelX();
    int velocidadY=this->model->getVelY();

    //caminar
    if((velocidadX!=0&&acelera==false ) || (velocidadY!=0&&acelera==false ))
    {
        if(frame<=MINFRAMECAMINA|| frame>=MAXFRAMECAMINA)
        {
            frame=MINFRAMECAMINA;
        } ;
        frame=frame + 1 ;

    }


    //pateo pelota

    if(this->model->patearPelota())
    {

        if(frame<=MINFRAMEPATEPELO || frame>=MAXFRAMEPATEPELO)
        {
            frame=MINFRAMEPATEPELO;
        }
        ++frame;

        this->model->terminoDePatearPelota();
    }


    //acelero
    if(this->model->getAcelero() && ((velocidadX != 0)||(velocidadY != 0)))
    {

        if(frame<=MINFRAMEACELE || frame>MAXFRAMEACELE) //frame/4=numero de spritted
        {
            frame=MINFRAMEACELE;
        }
        ++frame;
    }



    if (frame / 4 > MAXSPRITEUTILIZADO) //inicializo en 0 cuando ya me sobrepase en la cantidad de spritt(son 8 )


    {
        frame=0;

    }

    if ((this->model)->estaActivo())
    {
        this->texturaSeleccionado->render( (*this->model).getPosX() - camX, (*this->model).getPosY() - camY,NULL,this->model->getDireccion(),NULL,SDL_FLIP_NONE,gRenderer);
    }
    this->texturaJugador->render( (*this->model).getPosX() - camX, (*this->model).getPosY() - camY,currentClip,this->model->getDireccion(),NULL,SDL_FLIP_NONE,gRenderer);

}*/

void View_Jugador::render( int camX, int camY,SDL_Renderer * gRenderer )
{



    SDL_Rect* currentClip = &gSpriteClips[frame / 4 ];

    int acelera=this->model->getAcelero();
    int velocidadX=this->model->getVelX();
    int velocidadY=this->model->getVelY();

    //caminar
    if((velocidadX!=0&&acelera==false ) || (velocidadY!=0&&acelera==false ))
    {
        if(frame<=MINFRAMECAMINA|| frame>=MAXFRAMECAMINA)
        {
            frame=MINFRAMECAMINA;
        } ;
        frame=frame + 1 ;


    }


    //pateo pelota

    else if(this->model->patearPelota())
    {

        if(frame<=MINFRAMEPATEPELO || frame>=MAXFRAMEPATEPELO)
        {
            frame=MINFRAMEPATEPELO;
        }
        ++frame;

        this->model->terminoDePatearPelota();
        this->retardo=DESACTIVARRETARDO;
    }


    //acelero
    else if(this->model->getAcelero() && ((velocidadX != 0)||(velocidadY != 0)))
    {

        if(frame<=MINFRAMEACELE || frame>MAXFRAMEACELE) //frame/4=numero de spritted
        {
            frame=MINFRAMEACELE;
        }
        ++frame;

    }



    if (frame / 4 > MAXSPRITEUTILIZADO) //inicializo en 0 cuando ya me sobrepase en la cantidad de spritt(son 8 )


    {
        frame=0;

    }

    if ((this->model)->estaActivo())
    {
        this->texturaSeleccionado->render( (*this->model).getPosX() - camX, (*this->model).getPosY() - camY,NULL,this->model->getDireccion(),NULL,SDL_FLIP_NONE,gRenderer);
    }

    this->texturaJugador->render( (*this->model).getPosX() - camX, (*this->model).getPosY() - camY,currentClip,this->model->getDireccion(),NULL,SDL_FLIP_NONE,gRenderer);





}


bool View_Jugador::enEspera()
{

    bool espera=false;
    if (this->model->estaActivo())
    {
        int acelera=this->model->getAcelero();
        int velocidadX=this->model->getVelX();
        int velocidadY=this->model->getVelY();

        //caminar
        if((velocidadX!=0&&acelera==false ) || (velocidadY!=0&&acelera==false ))
        {


            this->retardo=DESACTIVARRETARDO;
            espera=false;
        }




        else if(this->model->patearPelota())
        {
            this->retardo=DESACTIVARRETARDO;
            espera= false;

        }


        //acelero
        else if(this->model->getAcelero())
        {
            this->retardo=DESACTIVARRETARDO;
            espera=false;

        }
        else
        {

            this->retardo=this->retardo+1;

            if(this->retardo>TIEMPORETARDO )
            {

                espera=true;

            }



        }





    }

    return espera;


}

void View_Jugador::renderEnEspera( int camX, int camY,SDL_Renderer * gRenderer )//SI ESTA EN ESPERA ENTONCES MUESTRA ESA SPRITTED
{



    SDL_Rect* currentClip = &gSpriteClips[frame / 4 ];
    // SDL_Rect* currentClipquieto = &gSpriteClips[1 / 4 ];







    if(frame<= 4|| frame>8) //frame/4=numero de spritted
    {
        frame=4;
    }

    ++frame;





    if (frame / 4 > 13) //inicializo en 0 cuando ya me sobrepase en la cantidad de spritt(son 8 )


    {
        frame=0;

    }

  if ((this->model)->estaActivo())
    {
        this->texturaSeleccionado->render( (*this->model).getPosX() - camX, (*this->model).getPosY() - camY,NULL,this->model->getDireccion(),NULL,SDL_FLIP_NONE,gRenderer);
    }

    this->texturaJugador->render( (*this->model).getPosX() - camX, (*this->model).getPosY() - camY,currentClip,this->model->getDireccion(),NULL,SDL_FLIP_NONE,gRenderer);




}



