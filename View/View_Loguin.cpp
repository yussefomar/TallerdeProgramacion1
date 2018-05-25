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
void RunGame();
void UpdateInputUsuario(std::string value);
void UpdateInputPassword(std::string value);
void UpdateInputEquipo(std::string value);
void UpdateInputPeticionPassword(std::string value);
void UpdateInputPeticionEquipo(std::string value);
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
SDL_Texture* ingresoUsuarioTexture;
SDL_Texture* ingresoPasswordTexture;
SDL_Texture* ingresoEquipoTexture;
SDL_Texture* backgroundTexture;
SDL_Texture* salidaTexture;

SDL_Rect bienvenidaRect;
SDL_Rect peticionUsuarioRect;
SDL_Rect peticionPasswordRect;
SDL_Rect peticionEquipoRect;
SDL_Rect ingresoUsuarioRect;
SDL_Rect ingresoPasswordRect;
SDL_Rect ingresoEquipoRect;
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

    //The gets the user's name
    StringInput ip("");
    //The gets the user's name
    StringInput actualUsuario(informacionIngreso.nombre);
    //The gets the user's name
    StringInput actualPassword(informacionIngreso.password);
    //The gets the user's name
    StringInput actualTeam(informacionIngreso.equipo);

    //Chequeamos toda la funcionalidad básica para el procesamiento.
    UpdateInputUsuario(informacionIngreso.nombre);
<<<<<<< Updated upstream
    //if(!informacionIngreso.nombre.empty()) nameEntered = true;

    UpdateInputPassword(informacionIngreso.password);
    //if(!informacionIngreso.password.empty()) passwordEntered = true;

    UpdateInputEquipo(informacionIngreso.equipo);
    //if(!informacionIngreso.equipo.empty()) teamEntered = true;

    if(informacionIngreso.error)
    {
        UpdateSalida(informacionIngreso.mensaje);
=======
    if(!informacionIngreso.nombre.empty())
        nameEntered = true;

    UpdateInputPassword(informacionIngreso.password);
    if(!informacionIngreso.password.empty())
        passwordEntered = true;

    UpdateInputEquipo(informacionIngreso.equipo);
    if(!informacionIngreso.equipo.empty())
        teamEntered = true;

    UpdateSalida(informacionIngreso.mensaje);
    if(informacionIngreso.error)
    {
>>>>>>> Stashed changes

        UpdateInputUsuario("");
        informacionIngreso.nombreIngresado = false;
        UpdateInputPassword("");
        informacionIngreso.passwordIngresado = false;
        UpdateInputEquipo("");
        informacionIngreso.equipoIngresado = false;

        UpdateInputPeticionPassword("");
        UpdateInputPeticionEquipo("");
    }

    informacionIngreso.error = false;

<<<<<<< Updated upstream
    //while( quit == false )
    //{
		SDL_Event event;
=======
    while( quit == false )
    {
        SDL_Event event;
>>>>>>> Stashed changes
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user hasn't entered their name yet
            if( informacionIngreso.nombreIngresado == false )
            {
                //Keep a copy of the current version of the string
                temp = actualUsuario.str;
                //Get user input
                actualUsuario.handle_input( event );

                //If the string was changed
                if( actualUsuario.str != temp )
                {
                    informacionIngreso.nombre = actualUsuario.str;
                    UpdateInputUsuario(actualUsuario.str);
                }

                //If the enter key was pressed
                if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_RETURN ) )
                {
<<<<<<< Updated upstream
                     informacionIngreso.nombreIngresado = true;
                     UpdateInputPeticionPassword("password:");
=======
                    //Change the flag
                    nameEntered = true;
                    UpdateInputPeticionPassword("password:");
>>>>>>> Stashed changes
                }
            }
            else if( informacionIngreso.passwordIngresado == false )
            {
                //Keep a copy of the current version of the string
                temp = actualPassword.str;
                //Get user input
                actualPassword.handle_input( event );

                //If the string was changed
                if( actualPassword.str != temp )
                {
                    informacionIngreso.password = actualPassword.str;
                    UpdateInputPassword(actualPassword.str);
                }

                //If the enter key was pressed
                if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_RETURN ) )
                {
                    informacionIngreso.passwordIngresado = true;
                    UpdateInputPeticionEquipo("ingrese equipo 1 o 2:");
                }
            }
            else if( informacionIngreso.equipoIngresado == false )
            {

                //Keep a copy of the current version of the string
                temp = actualTeam.str;
                //Get user input
                actualTeam.handle_input( event );

                //If the string was changed
                if( actualTeam.str != temp )
                {
                    informacionIngreso.equipo = actualTeam.str;;
                    UpdateInputEquipo(actualTeam.str);
                }

                //If the enter key was pressed
                if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_RETURN ) )
                {
                    informacionIngreso.equipoIngresado = true;
                    quit = true;
                }
            }

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
                informacionIngreso.error = true;
            }
        }

        //Update the screen
        /*if( SDL_Flip( screen ) == -1 )
        {
            informacionIngreso.error = true;
            return informacionIngreso;
        }*/
<<<<<<< Updated upstream
      /**************************************/
      Render();
    //}
=======
        /**************************************/
        Render();
    }
>>>>>>> Stashed changes

    informacionIngreso.nombre = actualUsuario.str;
    informacionIngreso.password = actualPassword.str;
    informacionIngreso.equipo = actualTeam.str;;
}


/*****************************************************************************/
/*****************************************************************************/
/**** METODOS AUXILIARES PROPIOS DE ESTA CLASE.  *******/
/*****************************************************************************/
/*****************************************************************************/

void RunGame()
{
    //Render();
//	std::cout << "Press any key to exit\n";
    //std::cin.ignore();
}

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
    SDL_RenderCopy( renderer, ingresoUsuarioTexture, nullptr, &ingresoUsuarioRect );
    SDL_RenderCopy( renderer, ingresoPasswordTexture, nullptr, &ingresoPasswordRect );
    SDL_RenderCopy( renderer, ingresoEquipoTexture, nullptr, &ingresoEquipoRect );
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
    fontPeticion = TTF_OpenFont( fontNamePeticion.c_str(), 45 );
    fontRespuesta = TTF_OpenFont( fontNameRespuesta.c_str(), 30 );

    // Error check
    if ( fontPeticion == nullptr || fontRespuesta == nullptr )
    {
        std::cout << " Falla al cargar una fuente : " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void UpdateInputUsuario(std::string value)
{
    SDL_Surface* ingresoUsuario = TTF_RenderText_Solid( fontRespuesta, value.c_str(), textColor );
    ingresoUsuarioTexture = SurfaceToTexture( ingresoUsuario );
    SDL_QueryTexture( ingresoUsuarioTexture, NULL, NULL, &ingresoUsuarioRect.w, &ingresoUsuarioRect.h );
    ingresoUsuarioRect.x = 30;
    ingresoUsuarioRect.y = peticionUsuarioRect.y + 50;
}

void UpdateInputPassword(std::string value)
{
    SDL_Surface* ingresoPassword = TTF_RenderText_Solid( fontRespuesta, value.c_str(), textColor );
    ingresoPasswordTexture = SurfaceToTexture( ingresoPassword );
    SDL_QueryTexture( ingresoPasswordTexture, NULL, NULL, &ingresoPasswordRect.w, &ingresoPasswordRect.h );
    ingresoPasswordRect.x = 30;
    ingresoPasswordRect.y = peticionPasswordRect.y + 50;
}

void UpdateInputEquipo(std::string value)
{
    SDL_Surface* ingresoEquipo = TTF_RenderText_Solid( fontRespuesta, value.c_str(), textColor );
    ingresoEquipoTexture = SurfaceToTexture( ingresoEquipo );
    SDL_QueryTexture( ingresoEquipoTexture, NULL, NULL, &ingresoEquipoRect.w, &ingresoEquipoRect.h );
    ingresoEquipoRect.x = 30;
    ingresoEquipoRect.y = peticionEquipoRect.y + 50;
}

void UpdateInputPeticionPassword(std::string value)
{
    SDL_Surface* peticionPassword = TTF_RenderText_Solid( fontPeticion, value.c_str(), textColor );
    peticionPasswordTexture = SurfaceToTexture( peticionPassword );
    SDL_QueryTexture( peticionPasswordTexture, NULL, NULL, &peticionPasswordRect.w, &peticionPasswordRect.h );
    peticionPasswordRect.x = 30;
    peticionPasswordRect.y = ingresoUsuarioRect.y + 50;
}

void UpdateInputPeticionEquipo(std::string value)
{
    SDL_Surface* peticionEquipo = TTF_RenderText_Solid( fontPeticion, value.c_str(), textColor );
    peticionEquipoTexture = SurfaceToTexture( peticionEquipo );
    SDL_QueryTexture( peticionEquipoTexture, NULL, NULL, &peticionEquipoRect.w, &peticionEquipoRect.h );
    peticionEquipoRect.x = 30;
    peticionEquipoRect.y = ingresoPasswordRect.y + 50;
}

void UpdateSalida(std::string value)
{
    SDL_Surface* salida = TTF_RenderText_Solid( fontRespuesta, value.c_str(), textColorMensaje );
    salidaTexture = SurfaceToTexture( salida );
    SDL_QueryTexture( salidaTexture, NULL, NULL, &salidaRect.w, &salidaRect.h );
    salidaRect.x = 100;
    salidaRect.y = ingresoEquipoRect.y + 50;
}

void CreateTextTextures()
{
    SDL_Surface* mensajeBienvenida = TTF_RenderText_Solid( fontPeticion, "BIENVENIDO A CORRELATIVIDAD!", textColor );
    bienvenidaTexture = SurfaceToTexture( mensajeBienvenida );
    SDL_QueryTexture( bienvenidaTexture, NULL, NULL, &bienvenidaRect.w, &bienvenidaRect.h );
    bienvenidaRect.x = 30;
    bienvenidaRect.y = 30;

    SDL_Surface* peticionUsuario = TTF_RenderText_Solid( fontPeticion, "INGRESE USUARIO:", textColor );
    peticionUsuarioTexture = SurfaceToTexture( peticionUsuario );
    SDL_QueryTexture( peticionUsuarioTexture, NULL, NULL, &peticionUsuarioRect.w, &peticionUsuarioRect.h );
    peticionUsuarioRect.x = 30;
    peticionUsuarioRect.y = bienvenidaRect.y + 80;

    SDL_Surface* ingresoUsuario = TTF_RenderText_Solid( fontRespuesta, "", textColor );
    ingresoUsuarioTexture = SurfaceToTexture( ingresoUsuario );
    SDL_QueryTexture( ingresoUsuarioTexture, NULL, NULL, &ingresoUsuarioRect.w, &ingresoUsuarioRect.h );
    ingresoUsuarioRect.x = 30;
    ingresoUsuarioRect.y = peticionUsuarioRect.y + 50;

    SDL_Surface* peticionPassword = TTF_RenderText_Solid( fontPeticion, "", textColor );
    peticionPasswordTexture = SurfaceToTexture( peticionPassword );
    SDL_QueryTexture( peticionPasswordTexture, NULL, NULL, &peticionPasswordRect.w, &peticionPasswordRect.h );
    peticionPasswordRect.x = 30;
    peticionPasswordRect.y = ingresoUsuarioRect.y + 50;

    SDL_Surface* ingresoPassword = TTF_RenderText_Solid( fontRespuesta, "", textColor );
    ingresoPasswordTexture = SurfaceToTexture( ingresoPassword );
    SDL_QueryTexture( ingresoPasswordTexture, NULL, NULL, &ingresoPasswordRect.w, &ingresoPasswordRect.h );
    ingresoPasswordRect.x = 30;
    ingresoPasswordRect.y = peticionPasswordRect.y + 50;

    SDL_Surface* peticionEquipo = TTF_RenderText_Solid( fontPeticion, "", textColor );
    peticionEquipoTexture = SurfaceToTexture( peticionEquipo );
    SDL_QueryTexture( peticionEquipoTexture, NULL, NULL, &peticionEquipoRect.w, &peticionEquipoRect.h );
    peticionEquipoRect.x = 30;
    peticionEquipoRect.y = ingresoPasswordRect.y + 50;

    SDL_Surface* ingresoEquipo = TTF_RenderText_Solid( fontRespuesta, "", textColor );
    ingresoEquipoTexture = SurfaceToTexture( ingresoEquipo );
    SDL_QueryTexture( ingresoEquipoTexture, NULL, NULL, &ingresoEquipoRect.w, &ingresoEquipoRect.h );
    ingresoEquipoRect.x = 30;
    ingresoEquipoRect.y = peticionEquipoRect.y + 50;

    SDL_Surface* salida = TTF_RenderText_Solid( fontRespuesta, "", textColor );
    salidaTexture = SurfaceToTexture( salida );
    SDL_QueryTexture( salidaTexture, NULL, NULL, &salidaRect.w, &salidaRect.h );
    salidaRect.x = 100;
    salidaRect.y = ingresoEquipoRect.y + 50;
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
    if ( !SetupTTF("Images/peticion.ttf", "Images/respuesta.otf") )
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
