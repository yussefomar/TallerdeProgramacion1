#include "../View/View.h"
#include "../Model/Model_Jugador.h"
#include <SDL2/SDL.h>

#define MARGEN 200
#define ANCHO_VENTANA 800
#define ALTO_VENTANA 600
#define CAMARAPOSICIONINICIALX (((ANCHO_NIVEL)/2)-((ANCHO_VENTANA)/2))
#define CAMARAPOSICIONINICIALY (((ALTO_NIVEL)/2)-((ALTO_VENTANA)/2))

View::View(Model* model)
{
    if(!this->inicializar())
    {
        NotifyError("SDL no se inicio: ", "View.cpp");
    }
    else
    {
        this->loadMedia();
        this->model = model;
        this->camaraStatic = { CAMARAPOSICIONINICIALX,CAMARAPOSICIONINICIALY, ANCHO_VENTANA, ALTO_VENTANA };
        this->camara = &(this->camaraStatic);
        this->model->setCamara(this->camara);
        this->viewModel = new ViewModel(this->model, this->gRenderer, this->camara,&(this->texturaCancha),&(this->texturaPelota),&(this->texturaJugador),&(this->texturaSeleccionado));
    }

}

View::~View()
{
    delete this->viewModel;
    this->close();
}

void View::ajustarCamara()
{

    NotifyMessage("Inicia: ajustarCamara", "View.cpp");

    this->camara->x = ( model->getPelota()->getPosX() + 12/ 2 ) - ANCHO_VENTANA/ 2;
    this->camara->y = ( model->getPelota()->getPosY() + 12 / 2 ) - ALTO_VENTANA/ 2;

    //Keep the this->camara->in bounds
    if( this->camara->x < 0 )
    {
        this->camara->x = 0;
    }
    if( this->camara->y < 0 )
    {
        this->camara->y = 0;
    }
    if( this->camara->x > ANCHO_NIVEL - this->camara->w )
    {
        this->camara->x = ANCHO_NIVEL - this->camara->w;
    }
    if( this->camara->y > ALTO_NIVEL - this->camara->h )
    {
        this->camara->y = ALTO_NIVEL - this->camara->h;
    }
    NotifyMessage("Finaliza: ajustarCamara", "View.cpp");

}

void View::render()
{
    NotifyMessage("Inicia: render", "View.cpp");
    this->ajustarCamara();
    SDL_SetRenderDrawColor( this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( this->gRenderer );

    this->viewModel->render();
    //this->mostrarCartel("Asdasd");
    this->mostrarCartel();
    SDL_RenderPresent( this->gRenderer );
    NotifyMessage("Finaliza: render", "View.cpp");

}

bool View::inicializar()
{
    bool exito = true;

    NotifyMessage("Inicia: inicializar", "View.cpp");

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        NotifyError("SDL could not initialize! SDL Error: ", "View.cpp");
        NotifyError(SDL_GetError(), "View.cpp");
        exito = false;
    }
    else
    {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
            NotifyWarning("Warning: Linear texture filtering not enabled!", "View.cpp");
        }

        //Create window
        this->window = SDL_CreateWindow( "Taller de Programacion - Correlatividad", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ANCHO_VENTANA, ALTO_VENTANA, SDL_WINDOW_SHOWN );
        if( this->window == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            NotifyError("Window could not be created! SDL Error: ", "View.cpp");
            NotifyError(SDL_GetError(), "View.cpp");
            exito = false;
        }
        else
        {
            //Create vsynced renderer for this->window
            this->gRenderer = SDL_CreateRenderer( this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( this->gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                NotifyError("Renderer could not be created! SDL Error: ", "View.cpp");
                NotifyError(SDL_GetError(), "View.cpp");
                exito = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    NotifyError("SDL_image could not initialize! SDL_image Error: ", "View.cpp");
                    NotifyError(IMG_GetError(), "View.cpp");
                    exito = false;
                }
            }
        }
    }
    NotifyMessage("Finaliza: inicializar", "View.cpp");

    return exito;
}

void View::mostrarCartel()
{
    this->panelMensaje.mostrarMensaje(this->mensaje, this->gRenderer);
}

void View::limpiarCartel()
{
    this->mensaje = "";
}

void View::cargarCartel(std::string value)
{
    this->mensaje = value;
}

void View::loadMedia()
{
    if( !texturaJugador.loadFromFile("Images/spritejugador.png",this->gRenderer) )
    {
        NotifyMessage("No se pudo cargar la Imagen del jugador, se usara una imagen por defecto", "View.cpp");
        texturaJugador.loadFromFile("Images/spritejugador2.png",this->gRenderer);
    }
    if( !texturaSeleccionado.loadFromFile( "Images/jugadorseleccionado.png",this->gRenderer) )
    {
        NotifyMessage("No se pudo cargar la Imagen de jugador seleccionado, se usara una imagen por defecto", "View.cpp");
        texturaSeleccionado.loadFromFile("Images/jugadorseleccionadoerror.png",this->gRenderer);
    }
    if( !texturaPelota.loadFromFile( "Images/pelota2.png",this->gRenderer) )
    {
        NotifyMessage("No se pudo cargar la Imagen de la pelota, se usara una imagen por defecto", "View.cpp");
        texturaPelota.loadFromFile("Images/pelota2error.png",this->gRenderer);
        texturaPelota.setColor(200,100,150);
    }
    if( !texturaCancha.loadFromFile( "Images/canchafubol.jpg",gRenderer) )
    {
        NotifyMessage("No se pudo cargar la Imagen de la cancha, se usara una imagen por defecto", "View.cpp");
        texturaCancha.loadFromFile("Images/canchafubolerror.jpg",this->gRenderer);
    }


}
void View::close()
{

    NotifyMessage("Inicia: close", "View.cpp");
    //Destroy this->window}
    SDL_DestroyRenderer( this->gRenderer );
    SDL_DestroyWindow( this->window );

    this->gRenderer = NULL;
    this->window = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
    NotifyMessage("Finaliza: close", "View.cpp");

}

void View::notificar(std::string entidad, char evento, char tipo)
{
    if(evento == DESCJUG)
    {
        this->cargarCartel("JUGADOR DESCONECTADO: " + entidad);
    }
    if(tipo == ERR_ESP)
    {
        this->cargarCartel("estamos esperando a un jugador.");
    }
    if(tipo == OK_CONTINUA)
    {
        this->limpiarCartel();
    }
}
