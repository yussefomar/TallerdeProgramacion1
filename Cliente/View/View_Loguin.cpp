//The headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>

#include "../View/View_Loguin.h"
#include "../View/StringInput.h"
#include "../View/InformacionIngreso.h"

using namespace std;

// Setup
bool InitEverything();
bool InitSDL();
bool CreateWindow();
bool CreateRenderer();
void SetupRenderer();
// Setup Texto
bool SetupTTF( const std::string &fontNamePeticion,  const std::string &fontNameRespuesta );
SDL_Texture* LoadTexture( const std::string &str );
SDL_Texture* SurfaceToTexture( SDL_Surface* surf );
void CreateTextTextures();
// Update and Render
void Render();
void UpdateInputUsuario(std::string value);
void UpdateInputPassword(std::string value);
void UpdateInputEquipo(std::string value);
void UpdateInputIp(std::string value);
void UpdateInputPuerto(std::string value);
void UpdateInputPeticionUsuario(std::string value);
void UpdateInputPeticionPassword(std::string value);
void UpdateInputPeticionEquipo(std::string value);
void UpdateInputPeticionPuerto(std::string value);
void UpdateSalida(std::string value);
// Stuff for text rendering
TTF_Font* fontPeticion;
TTF_Font* fontRespuesta;

SDL_Color textColorMensaje = { 255, 150, 150, 255 }; // white
SDL_Color textColor = { 255, 255, 255, 255 }; // white
SDL_Color backgroundColor = { 0, 0, 0, 255 }; // red

SDL_Texture* bienvenidaTexture;
SDL_Texture* peticionUsuarioTexture;
SDL_Texture* peticionPasswordTexture;
SDL_Texture* peticionEquipoTexture;
SDL_Texture* peticionIpTexture;
SDL_Texture* peticionPuertoTexture;
SDL_Texture* ingresoUsuarioTexture;
SDL_Texture* ingresoPasswordTexture;
SDL_Texture* ingresoEquipoTexture;
SDL_Texture* ingresoIpTexture;
SDL_Texture* ingresoPuertoTexture;
SDL_Texture* backgroundTexture;
SDL_Texture* salidaTexture;

SDL_Rect bienvenidaRect;
SDL_Rect peticionUsuarioRect;
SDL_Rect peticionPasswordRect;
SDL_Rect peticionEquipoRect;
SDL_Rect peticionIpRect;
SDL_Rect peticionPuertoRect;
SDL_Rect ingresoUsuarioRect;
SDL_Rect ingresoPasswordRect;
SDL_Rect ingresoEquipoRect;
SDL_Rect ingresoPuertoRect;
SDL_Rect ingresoIpRect;
SDL_Rect backgroundRect;
SDL_Rect salidaRect;

SDL_Rect windowRect = { 300, 300, 800, 600 };

SDL_Window* window;
SDL_Renderer* renderer;


View_Loguin::View_Loguin(int i)
{

}

View_Loguin::~View_Loguin()
{

}

bool View_Loguin::Inicializar()
{
    return InitEverything();
}
void View_Loguin::Cerrar()
{
    // Clean up font
    TTF_CloseFont( fontPeticion );
    TTF_CloseFont( fontRespuesta );
    //Quit SDL_ttf
    TTF_Quit();
    //Quit SDL
    SDL_Quit();
}

void View_Loguin::Procesar(InformacionIngreso &informacionIngreso)
{
    std::string temp = "";
    bool quit = false;
    //Creamos los manejadores para cada ingreso.
    StringInput actualUsuario(informacionIngreso.nombre);
    StringInput actualPassword(informacionIngreso.password);
    StringInput actualTeam(informacionIngreso.equipo);
    StringInput actualIp(informacionIngreso.ip);
    StringInput actualPuerto(informacionIngreso.puerto);
    //Actualizamos con lo que ya nos viene por defecto.
    UpdateInputUsuario(informacionIngreso.nombre);
    UpdateInputPassword(informacionIngreso.password);
    UpdateInputEquipo(informacionIngreso.equipo);
    UpdateInputIp(informacionIngreso.ip);
    UpdateInputPuerto(informacionIngreso.puerto);

    informacionIngreso.error = false;
    UpdateSalida(informacionIngreso.mensaje);

    if(informacionIngreso.ipIngresado) UpdateInputPeticionPuerto("puerto:");
    else  UpdateInputPeticionPuerto("");
    if(informacionIngreso.puertoIngresado) UpdateInputPeticionUsuario("nombre:");
    else UpdateInputPeticionUsuario("");
    if(informacionIngreso.nombreIngresado) UpdateInputPeticionPassword("password:");
    else  UpdateInputPeticionPassword("");
    if(informacionIngreso.passwordIngresado) UpdateInputPeticionEquipo("equipo 1 o 2:");
    else  UpdateInputPeticionEquipo("");

while(!quit)
    {
  SDL_Event event;
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            if( informacionIngreso.ipIngresado == false || informacionIngreso.puertoIngresado == false )
            {
                if(!informacionIngreso.ipIngresado)
                {
                    temp = actualIp.str;
                    actualIp.handle_input( event );

                    if( actualIp.str != temp )
                    {
                        informacionIngreso.ip = actualIp.str;
                        UpdateInputIp(actualIp.str);
                    }

                    if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_RETURN ) )
                    {
                         informacionIngreso.ipIngresado = true;
                         UpdateInputPeticionPuerto("puerto:");
                         quit = true;
                    }
                }
else if(!informacionIngreso.puertoIngresado)
                {
                    temp = actualPuerto.str;
                    actualPuerto.handle_input( event );

                    if( actualPuerto.str != temp )
                    {
                        informacionIngreso.puerto = actualPuerto.str;
                        UpdateInputPuerto(actualPuerto.str);
                    }

                    if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_RETURN ) )
                    {
                         informacionIngreso.puertoIngresado = true;
                         UpdateInputPeticionUsuario("nombre:");
                         quit = true;
                    }
                }
            }
            else if( informacionIngreso.nombreIngresado == false )
            {
                temp = actualUsuario.str;
                actualUsuario.handle_input( event );

                if( actualUsuario.str != temp )
                {
 informacionIngreso.nombre = actualUsuario.str;
                    UpdateInputUsuario(actualUsuario.str);
                }

                if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_RETURN ) )
                {
                     informacionIngreso.nombreIngresado = true;
                     UpdateInputPeticionPassword("password:");
                     quit = true;
                }
            }
            else if( informacionIngreso.passwordIngresado == false )
            {
                temp = actualPassword.str;
                actualPassword.handle_input( event );

                if( actualPassword.str != temp )
                {
                    informacionIngreso.password = actualPassword.str;
                    UpdateInputPassword(actualPassword.str);
                }

                if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_RETURN ) )
                {
                    informacionIngreso.passwordIngresado = true;
                     UpdateInputPeticionEquipo("equipo 1 o 2:");
                    quit = true;
                }
            }
            else if( informacionIngreso.equipoIngresado == false )
            {
                temp = actualTeam.str;
                actualTeam.handle_input( event );

                if( actualTeam.str != temp )
                {
                    informacionIngreso.equipo = actualTeam.str;;
                    UpdateInputEquipo(actualTeam.str);
                }

                if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_RETURN ) )
                {
                    informacionIngreso.equipoIngresado = true;
                    quit = true;
                }
            }

            if( event.type == SDL_QUIT )
            {
                informacionIngreso.equipoIngresado = true;
            }
        }
        /*
        //If the user has Xed out the window
        if( event.type == SDL_QUIT )
        {
            informacionIngreso.error = true;
            return informacionIngreso;
        }*/
      /**************************************/
      Render();
        informacionIngreso.nombre = actualUsuario.str;
        informacionIngreso.password = actualPassword.str;
        informacionIngreso.equipo = actualTeam.str;
        informacionIngreso.ip = actualIp.str;
        informacionIngreso.puerto = actualPuerto.str;
    }

}


/*****************************************************************************/
/*****************************************************************************/
/**** METODOS AUXILIARES PROPIOS DE ESTA CLASE.  *******/
/*****************************************************************************/
/*****************************************************************************/

void Render()
{
    // Clear the window and make it all red
    SDL_RenderClear( renderer );

    //Para el backgroundImage
    SDL_RenderCopy( renderer, backgroundTexture, NULL, &backgroundRect );

    // Render our text objects ( like normal )
    SDL_RenderCopy( renderer, bienvenidaTexture, nullptr, &bienvenidaRect );
    SDL_RenderCopy( renderer, peticionUsuarioTexture, nullptr, &peticionUsuarioRect );
    SDL_RenderCopy( renderer, peticionPasswordTexture, nullptr, &peticionPasswordRect );
    SDL_RenderCopy( renderer, peticionEquipoTexture, nullptr, &peticionEquipoRect );
    SDL_RenderCopy( renderer, peticionIpTexture, nullptr, &peticionIpRect );
    SDL_RenderCopy( renderer, peticionPuertoTexture, nullptr, &peticionPuertoRect );
    SDL_RenderCopy( renderer, ingresoUsuarioTexture, nullptr, &ingresoUsuarioRect );
    SDL_RenderCopy( renderer, ingresoPasswordTexture, nullptr, &ingresoPasswordRect );
    SDL_RenderCopy( renderer, ingresoEquipoTexture, nullptr, &ingresoEquipoRect );
    SDL_RenderCopy( renderer, ingresoIpTexture, nullptr, &ingresoIpRect );
    SDL_RenderCopy( renderer, ingresoPuertoTexture, nullptr, &ingresoPuertoRect );
    SDL_RenderCopy( renderer, salidaTexture, nullptr, &salidaRect );

    // Render the changes above
    SDL_RenderPresent( renderer );
}

// Initialization ++
// ==================================================================
bool SetupTTF(const std::string &fontNamePeticion,const std::string &fontNameRespuesta)
{
    // SDL2_TTF needs to be initialized just like SDL2
    if ( TTF_Init() == -1 )
    {
        std::cout << " Falla al inicializar el TTF : " << SDL_GetError() << std::endl;
        return false;
    }

    // Load our fonts, with a huge size
    fontPeticion = TTF_OpenFont( fontNamePeticion.c_str(), 25 );
    fontRespuesta = TTF_OpenFont( fontNameRespuesta.c_str(), 20 );

    // Error check
    if ( fontPeticion == nullptr || fontRespuesta == nullptr )
    {
        std::cout << " Falla al cargar una fuente : " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void UpdateInputIp(std::string value)
{
    SDL_Surface* ingresoIp = TTF_RenderText_Solid( fontRespuesta, value.c_str(), textColor );
    ingresoIpTexture = SurfaceToTexture( ingresoIp );
    SDL_QueryTexture( ingresoIpTexture, NULL, NULL, &ingresoIpRect.w, &ingresoIpRect.h );
    ingresoIpRect.x = 30;
    ingresoIpRect.y = peticionIpRect.y + 25;
}

void UpdateInputPuerto(std::string value)
{
    SDL_Surface* ingresoPuerto = TTF_RenderText_Solid( fontRespuesta, value.c_str(), textColor );
    ingresoPuertoTexture = SurfaceToTexture( ingresoPuerto );
    SDL_QueryTexture( ingresoPuertoTexture, NULL, NULL, &ingresoPuertoRect.w, &ingresoPuertoRect.h );
    ingresoPuertoRect.x = 30;
    ingresoPuertoRect.y = peticionPuertoRect.y + 30;
}

void UpdateInputUsuario(std::string value)
{
    SDL_Surface* ingresoUsuario = TTF_RenderText_Solid( fontRespuesta, value.c_str(), textColor );
    ingresoUsuarioTexture = SurfaceToTexture( ingresoUsuario );
    SDL_QueryTexture( ingresoUsuarioTexture, NULL, NULL, &ingresoUsuarioRect.w, &ingresoUsuarioRect.h );
    ingresoUsuarioRect.x = 30;
    ingresoUsuarioRect.y = peticionUsuarioRect.y + 30;
}

void UpdateInputPassword(std::string value)
{
    SDL_Surface* ingresoPassword = TTF_RenderText_Solid( fontRespuesta, value.c_str(), textColor );
    ingresoPasswordTexture = SurfaceToTexture( ingresoPassword );
    SDL_QueryTexture( ingresoPasswordTexture, NULL, NULL, &ingresoPasswordRect.w, &ingresoPasswordRect.h );
    ingresoPasswordRect.x = 30;
    ingresoPasswordRect.y = peticionPasswordRect.y + 30;
}

void UpdateInputEquipo(std::string value)
{
    SDL_Surface* ingresoEquipo = TTF_RenderText_Solid( fontRespuesta, value.c_str(), textColor );
    ingresoEquipoTexture = SurfaceToTexture( ingresoEquipo );
    SDL_QueryTexture( ingresoEquipoTexture, NULL, NULL, &ingresoEquipoRect.w, &ingresoEquipoRect.h );
    ingresoEquipoRect.x = 30;
    ingresoEquipoRect.y = peticionEquipoRect.y + 30;
}

void UpdateInputPeticionIp(std::string value)
{
    SDL_Surface* peticionIp = TTF_RenderText_Solid( fontPeticion, value.c_str(), textColor );
    peticionIpTexture = SurfaceToTexture( peticionIp );
    SDL_QueryTexture( peticionIpTexture, NULL, NULL, &peticionIpRect.w, &peticionIpRect.h );
    peticionIpRect.x = 30;
    peticionIpRect.y = bienvenidaRect.y + 50;
}

void UpdateInputPeticionPuerto(std::string value)
{
    SDL_Surface* peticionPuerto = TTF_RenderText_Solid( fontPeticion, value.c_str(), textColor );
    peticionPuertoTexture = SurfaceToTexture( peticionPuerto );
    SDL_QueryTexture( peticionPuertoTexture, NULL, NULL, &peticionPuertoRect.w, &peticionPuertoRect.h );
    peticionPuertoRect.x = 30;
    peticionPuertoRect.y = ingresoIpRect.y + 30;
}

void UpdateInputPeticionUsuario(std::string value)
{
    SDL_Surface* peticionUsuario = TTF_RenderText_Solid( fontPeticion, value.c_str(), textColor );
    peticionUsuarioTexture = SurfaceToTexture( peticionUsuario );
    SDL_QueryTexture( peticionUsuarioTexture, NULL, NULL, &peticionUsuarioRect.w, &peticionUsuarioRect.h );
    peticionUsuarioRect.x = 30;
    peticionUsuarioRect.y = ingresoPuertoRect.y + 30;
}

void UpdateInputPeticionPassword(std::string value)
{
    SDL_Surface* peticionPassword = TTF_RenderText_Solid( fontPeticion, value.c_str(), textColor );
    peticionPasswordTexture = SurfaceToTexture( peticionPassword );
    SDL_QueryTexture( peticionPasswordTexture, NULL, NULL, &peticionPasswordRect.w, &peticionPasswordRect.h );
    peticionPasswordRect.x = 30;
    peticionPasswordRect.y = ingresoUsuarioRect.y + 30;
}

void UpdateInputPeticionEquipo(std::string value)
{
    SDL_Surface* peticionEquipo = TTF_RenderText_Solid( fontPeticion, value.c_str(), textColor );
    peticionEquipoTexture = SurfaceToTexture( peticionEquipo );
    SDL_QueryTexture( peticionEquipoTexture, NULL, NULL, &peticionEquipoRect.w, &peticionEquipoRect.h );
    peticionEquipoRect.x = 30;
    peticionEquipoRect.y = ingresoPasswordRect.y + 30;
}

void UpdateSalida(std::string value)
{
    SDL_Surface* salida = TTF_RenderText_Solid( fontRespuesta, value.c_str(), textColorMensaje );
    salidaTexture = SurfaceToTexture( salida );
    SDL_QueryTexture( salidaTexture, NULL, NULL, &salidaRect.w, &salidaRect.h );
    salidaRect.x = 100;
    salidaRect.y = ingresoEquipoRect.y + 30;
}

void CreateTextTextures()
{
    SDL_Surface* mensajeBienvenida = TTF_RenderText_Solid( fontPeticion, "BIENVENIDO A CORRELATIVIDAD!", textColor );
    bienvenidaTexture = SurfaceToTexture( mensajeBienvenida );
    SDL_QueryTexture( bienvenidaTexture, NULL, NULL, &bienvenidaRect.w, &bienvenidaRect.h );
    bienvenidaRect.x = 30;
    bienvenidaRect.y = 30;

    UpdateInputPeticionIp("IP:");
    UpdateInputIp("");

    UpdateInputPeticionPuerto("");
    UpdateInputPuerto("");

    UpdateInputPeticionUsuario("");
    UpdateInputUsuario("");

    UpdateInputPeticionPassword("");
    UpdateInputPassword("");

    UpdateInputPeticionEquipo("");
    UpdateInputEquipo("");

    UpdateSalida("");
}

// Convert an SDL_Surface to SDL_Texture. We've done this before, so I'll keep it short
SDL_Texture* SurfaceToTexture( SDL_Surface* surf )
{
    SDL_Texture* text;

    text = SDL_CreateTextureFromSurface( renderer, surf );

    SDL_FreeSurface( surf );

    return text;
}

bool InitEverything()
{
    if ( !InitSDL() )
        return false;

    if ( !CreateWindow() )
        return false;

    if ( !CreateRenderer() )
        return false;

    SetupRenderer();

    //Iniciamos las fuentes
    if ( !SetupTTF("Images/peticion.ttf", "Images/Roboto-Regular.ttf") )
        return false;

    CreateTextTextures();

    backgroundRect.x = 0;
    backgroundRect.y = 0;
    backgroundRect.w = windowRect.w;
    backgroundRect.h = windowRect.h;

    backgroundTexture = LoadTexture( "Images/background.jpg" );

    return true;
}


bool InitSDL()
{
    if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}


bool CreateWindow()
{
    window = SDL_CreateWindow( "TALLER DE PROGRAMACION I", windowRect.x, windowRect.y, windowRect.w, windowRect.h, 0 );

    if ( window == nullptr )
    {
        std::cout << "Falla al crear la ventana de loguin : " << SDL_GetError();
        return false;
    }

    return true;
}


bool CreateRenderer()
{
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

    if ( renderer == nullptr )
    {
        std::cout << "Failed to create renderer : " << SDL_GetError();
        return false;
    }

    return true;
}


void SetupRenderer()
{
    // Set size of renderer to the same as window
    SDL_RenderSetLogicalSize( renderer, windowRect.w, windowRect.h );

    // Set color of renderer to red
    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
}

SDL_Texture* LoadTexture( const std::string &str )
{
    // Load image as SDL_Surface
    SDL_Surface* surface = IMG_Load( str.c_str() );

    // SDL_Surface is just the raw pixels
    // Convert it to a hardware-optimzed texture so we can render it
    SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, surface );

    // Don't need the orignal texture, release the memory
    SDL_FreeSurface( surface );

    return texture;
}
