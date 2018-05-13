//The headers
/** #include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <stdexcept>

using namespace std;

#include "../View/StringInput.h"
#include "../View/View_Loguin.h"

//Screen attributes
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *message_equipo = NULL;
SDL_Surface *message_password = NULL;
SDL_Surface *message = NULL;
SDL_Surface *background = NULL;
SDL_Surface *tittle = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

//The font
TTF_Font *fontBienvenida = NULL;
TTF_Font *fontUsuario = NULL;
TTF_Font *fontPassword = NULL;
TTF_Font *fontEquipo = NULL;
TTF_Font *fontRespuesta = NULL;

//The color of the font
SDL_Color textColor = { 0xFF, 0xFF, 0xFF };


SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}


// Imprime por pantalla cierto texto específico.
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "TALLER DE PROGRAMACION I", NULL );

    //If everything initialized fine
    return true;
}


//Limpiamos todo aquello que hemos cargado.
void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( message );
    SDL_FreeSurface( message_password );
    SDL_FreeSurface( tittle );

    //Close the font that was used
    TTF_CloseFont( fontBienvenida );
    TTF_CloseFont( fontUsuario );
    TTF_CloseFont( fontPassword );
    TTF_CloseFont( fontRespuesta );
    TTF_CloseFont( fontEquipo );

    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}

//Cargamos todos los archivos que fuesen necesarios.
bool load_files()
{
    //Load the background image
    background = load_image( "../Images/background.jpg" );
    //Open the font
    fontBienvenida = TTF_OpenFont( "../Images/peticion.ttf", 42 );
    fontUsuario = TTF_OpenFont( "../Images/peticion.ttf", 42 );
    fontPassword = TTF_OpenFont( "../Images/peticion.ttf", 42 );
    fontEquipo = TTF_OpenFont( "../Images/peticion.ttf", 42 );
    fontRespuesta = TTF_OpenFont( "../Images/respuesta.otf", 42 );

    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }
    //If there was an error in loading the font
    if( fontBienvenida == NULL )
    {
        return false;
    }
    if( fontUsuario == NULL )
    {
        return false;
    }
    if( fontPassword == NULL )
    {
        return false;
    }
    if( fontRespuesta == NULL )
    {
        return false;
    }
    if( fontEquipo == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}
//Constructor
View_Loguin::View_Loguin(int i)
{
    //Initialize
    if( init() == false )
    {
        throw std::invalid_argument( "falla el init del viewLoguin" );
    }

    //Load the files
    if( load_files() == false )
    {
        throw std::invalid_argument( "falla el loadFiles del viewLoguin" );
    }
}
//Destructor
View_Loguin::~View_Loguin()
{
    //Clean up
    clean_up();
}
std::string View_Loguin::procesar()
{
    //Enable Unicode
    SDL_EnableUNICODE( SDL_ENABLE );

    //Quit flag
    bool quit = false;
    std::string temp = "";

    //Keep track if whether or not the user has entered their name
    bool nameEntered = false;
    bool passwordEntered = false;
    bool teamEntered = false;

    //The gets the user's name
    StringInput ip(1);
    //The gets the user's name
    StringInput actualUsuario(1);
    //The gets the user's name
    StringInput actualPassword(1);
    //The gets the user's name
    StringInput actualTeam(1);

    tittle = TTF_RenderText_Solid( fontBienvenida, "bienvenidos a correlatividad:", textColor );

    //Set the message
    message = TTF_RenderText_Solid( fontUsuario, "usuario:", textColor );

    //While the user hasn't quit
    while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user hasn't entered their name yet
            if( nameEntered == false )
            {
                //Keep a copy of the current version of the string
                temp = actualUsuario.str;
                //Get user input
                actualUsuario.handle_input( event );

                //If the string was changed
                if( actualUsuario.str != temp )
                {
                    //Free the old surface
                    SDL_FreeSurface( actualUsuario.text );

                    //Render a new text surface
                    actualUsuario.text = TTF_RenderText_Solid( fontRespuesta, actualUsuario.str.c_str(), textColor );
                }

                //If the enter key was pressed
                if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_RETURN ) )
                {
                     //Change the flag
                     nameEntered = true;

                     SDL_FreeSurface( message_password );

                    //Change the message
                     message_password = TTF_RenderText_Solid( fontPassword, "password:", textColor );
                }
            }
            else if( passwordEntered == false )
            {
                //Keep a copy of the current version of the string
                temp = actualPassword.str;
                //Get user input
                actualPassword.handle_input( event );

                //If the string was changed
                if( actualPassword.str != temp )
                {
                    //Free the old surface
                    SDL_FreeSurface( actualPassword.text );

                    //Render a new text surface
                    actualPassword.text = TTF_RenderText_Solid( fontRespuesta, actualPassword.str.c_str(), textColor );
                }

                //If the enter key was pressed
                if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_RETURN ) )
                {
                    //Change the flag
                    passwordEntered = true;

                     SDL_FreeSurface( message_equipo );

                    //Change the message
                     message_equipo = TTF_RenderText_Solid( fontEquipo, "ingrese equipo 1 o 2:", textColor );
                }

            }else if( teamEntered == false )
            {

                //Keep a copy of the current version of the string
                temp = actualTeam.str;
                //Get user input
                actualTeam.handle_input( event );

                //If the string was changed
                if( actualTeam.str != temp )
                {
                    //Free the old surface
                    SDL_FreeSurface( actualTeam.text );

                    //Render a new text surface
                    actualTeam.text = TTF_RenderText_Solid( fontRespuesta, actualTeam.str.c_str(), textColor );
                }

                //If the enter key was pressed
                if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_RETURN ) )
                {
                    teamEntered = true;
                    quit = true;
                }
            }

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        //Apply the background
        apply_surface( 0, 0, background, screen );

        //Show the message
        apply_surface( 30, 20, tittle, screen );

        //Show the name on the screen
        apply_surface( 30, 100, message, screen );
        apply_surface( 30, 150, actualUsuario.text, screen );

        //Show the password on the screen
        apply_surface( 30, 200, message_password, screen );
        apply_surface( 30, 250, actualPassword.text, screen );
        //Show the team on the screen
        apply_surface( 30, 300, message_equipo, screen );
        apply_surface( 30, 350, actualTeam.text, screen );

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return "";
        }
    }

    std::string datos = actualUsuario.str + ";" + actualPassword.str + ";" + actualTeam.str;
    //Disable Unicode
    SDL_EnableUNICODE( SDL_DISABLE );

    return datos;
}
**/
