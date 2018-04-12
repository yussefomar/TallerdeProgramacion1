#include "View.h"
//dimension de pantalla
static const int MARGEN = 200;
static const int ANCHO_VENTANA = 800;
static const int ALTO_VENTANA = 600;
static const int CAMARAPOSICIONINICIALX = 300;
static const int CAMARAPOSICIONINICIALY = 600;

View::View()
{
    //The camera area
    this->camera = {CAMARAPOSICIONINICIALX,
                    CAMARAPOSICIONINICIALY,
                    ANCHO_VENTANA,
                    ALTO_VENTANA
                   };
    //The window we'll be rendering to
    this->window = NULL;
    //The window renderer
    this->gRenderer = NULL;


    if (!this->inicializar())
    {
        printf("%s\n", "Fallo el inicializar");
        return;
    }
    if (!this->loadMedia())
    {
        printf("%s\n", "Fallo el loadMedia");
        return;
    }
}

View::~View()
{
    this->close();
}

bool View::inicializar()
{
    bool exito = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        exito = false;
    }
    else
    {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        this->window = SDL_CreateWindow( "Taller de Programacion - Correlatividad",
                                         SDL_WINDOWPOS_UNDEFINED,
                                         SDL_WINDOWPOS_UNDEFINED,
                                         ANCHO_VENTANA,
                                         ALTO_VENTANA,
                                         SDL_WINDOW_SHOWN );
        if(this->window == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            exito = false;
        }
        else
        {
            //Create vsynced renderer for window
            this->gRenderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if(this->gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                exito = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    exito = false;
                }
            }
        }
    }
    return exito;
}

bool View::loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load background texture
    if( !this->texturaCancha.loadFromFile( "Images/canchafubol.jpg", this->gRenderer ) )
    {
        printf( "Failed to load background texture!\n" );
        success = false;
    }


    return success;
}

void View::close()
{

    this->texturaCancha.free();
    //texturaJugador.free();

    //Destroy window}
    SDL_DestroyRenderer( this->gRenderer );
    SDL_DestroyWindow( this->window );

    this->gRenderer = NULL;
    this->window = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

void View::update()
{
    return;
}

void View::setModel(Model& model)
{
    this->model = model;
    //Muy para salir del apuro...
    this->viewJugador.SetModel(&(this->model.getActivePlayer()))
}

void View::render()
{
    Jugador* jugador = this->model.getActivePlayer();
    //centrar camara sobre el jugador.
    if ( (this->camera.x + ANCHO_VENTANA-MARGEN)<(jugador->getPosX()+Jugador::ANCHO_JUGADOR / 2 ))
    {
        camera.x +=3; //=( jugador.getPosX() + Jugador::ANCHO_JUGADOR / 2 ) - ANCHO_VENTANA/ 2;
    }
    if ( (camera.x +MARGEN)>(jugador.getPosX()+Jugador::ANCHO_JUGADOR / 2 ))
    {
        camera.x -=3;// ( jugador.getPosX() + Jugador::ANCHO_JUGADOR / 2 ) - ANCHO_VENTANA/ 2;
    }

    if ((camera.y + ALTO_VENTANA-MARGEN)<(jugador.getPosY()+Jugador::ALTO_JUGADOR / 2 ))
    {
        camera.y +=3;//= ( jugador.getPosY() + Jugador::ALTO_JUGADOR / 2 ) - ALTO_VENTANA / 2;
    }
    if ((camera.y +MARGEN)>(jugador.getPosY()+Jugador::ALTO_JUGADOR / 2 ))
    {
        camera.y -=3;//= ( jugador.getPosY() + Jugador::ALTO_JUGADOR / 2 ) - ALTO_VENTANA / 2;
    }

}
