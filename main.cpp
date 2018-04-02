#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Model/Model_Jugador.h"
#include "Utils/Util_Logger.h"
#include "Model/LTexture.h"
#include "View/View_Jugador.h"
using namespace std;


//dimension del nivel
//const int ANCHO_NIVEL = 2048;
//const int ALTO_NIVEL = 1318;

//dimension de pantalla
const int ANCHO_VENTANA = 800;
const int ALTO_VENTANA = 600;


unsigned short logLevel;
Util_Logger logger;

void obtenerControles() {
    cout << "obtenerControles" << endl;
}

void actualizarModelo() {
    cout << "actualizarModelo" << endl;
}

void renderizar() {
    cout << "renderizar" << endl;
}

/**

 EL CÓDIGO QUE SIGUE ES MERAMENTE UN EJEMPLO DONDE ESTABA PROBANDO.-
 EJEMPLO PARA LEER LAS KEY Y ARMAR LA VENTANA CON SDL.
 EN PROGRESO, TOMARLO SOLO COMO UN EJEMPLO A MEDIO CAMINO.-

 PARA QUE COMPILE SDL TIENEN QUE AGREGAR EN Project -> Build Options -> Linker Setting -> Other Linker Options:

 -lSDL2

**/

bool KEYS[322];  // 322 is the number of SDLK_DOWN events

/*void inicializar()
{
    for(int i = 0; i < 322; i++)
    {
        // init them all to false
        KEYS[i] = false;
    }
    // you can configure this how you want,
    // but it makes it nice for when you want to register a key continuously being held down
    // SDL_EnableKeyRepeat(0,0);
}*/

void keyboard()
{
    // message processing loop
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        // check for messages
        switch (event.type) {
        // exit if the window is closed
        case SDL_QUIT:
            //game_state = 0; // set game state to done,(do what you want here)
            break;
        // check for keypresses
        case SDL_KEYDOWN:
            KEYS[event.key.keysym.sym] = true;
            cout << "apretamos algo." << endl;
            break;
        case SDL_KEYUP:
            KEYS[event.key.keysym.sym] = false;
            cout << "soltamos algo." << endl;
            break;
        default:
            break;
        }
    } // end of message processing
}

void handleInput()
{
    if(KEYS[SDLK_LEFT]) {
        cout << "SDLK_LEFT" << endl;
    }
    if(KEYS[SDLK_RIGHT]) { // move right

        cout << "SDLK_RIGHT" << endl;
    }
    if(KEYS[SDLK_UP]) { // move up
        cout << "SDLK_UP" << endl;
    }
    if(KEYS[SDLK_DOWN]) { // move down
        cout << "SDLK_DOWN" << endl;
    }
    if(KEYS[SDLK_s]) { // shoot
        cout << "SDLK_s" << endl;
    }
    if(KEYS[SDLK_q]) {
        cout << "SDLK_q" << endl;
    }

    if(KEYS[SDLK_r]) {
        cout << "SDLK_r" << endl;
    }

    if(KEYS[SDLK_ESCAPE]) {
        cout << "SDLK_r" << endl;
    }
}

//Frees media and shuts down SDL
//void close();

//The window we'll be rendering to
SDL_Window* window = NULL;
//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene textures
LTexture texturaJugador;
LTexture texturaCancha;

bool inicializar()
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
		window = SDL_CreateWindow( "Taller de Programacion - Correlatividad", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ANCHO_VENTANA, ALTO_VENTANA, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			exito = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				exito = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

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

bool loadMedia()
{
	//Loading success flag
	bool success = true;


	//Load background texture
	if( !texturaCancha.loadFromFile( "Images/canchafubol.jpg",gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}

    //Load dot texture
	if( !texturaJugador.loadFromFile( "Images/soccer.png", gRenderer) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	return success;
}

void close()
{

    texturaCancha.free();
    texturaJugador.free();

	//Destroy window}
    SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( window );

    gRenderer = NULL;
	window = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	/********************************************************************************************/
	// Inicializar el log.
	logger.createFile(3);
    /**
	Si queremos usar el logger mientras leemos el archivo de configuracion debemos crearlo como
	arriba, luego podemos llamar al método updateLevel para ponerle el nivel que corresponda.

    En cualquier parte del código que querramos usar el logger podemos llamar a los siguientes
    métodos según corresponda, luego según el level del logger, escribirá o no en el archivo.
    por ejemplo en un catch donde saltó una excepción ponemos log.writeErrorLine y si el level
    está configurado para escribir errores los pondra en el archivo.
    **/
	logger.writeErrorLine("Ejemplo de Error."); //nivel bajo, siempre mostramos errores.
	logger.writeWarningLine("Ejemplo de Warning."); //nivel medio, mostramos errores y warnings.
	logger.writeMessageLine("Ejemplo de linea común."); //nivel alto, se escribe todo.
	/********************************************************************************************/

	/********************************************************************************************/


  	if( !inicializar() )
	{
		printf( "Fallo al Inicializar!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
    SDL_Event e;
    bool quit = false;

    //The dot that will be moving around on the screen
    Jugador jugador;

    //The camera area
    SDL_Rect camera = { 0, 0, ANCHO_VENTANA, ALTO_VENTANA };

    while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

					//Handle input Jugador
					jugador.handleEvent( e );
				}
                //Move the dot
				jugador.move();

				//Center the camera over the dot
				camera.x = ( jugador.getPosX() + Jugador::ANCHO_JUGADOR / 2 ) - ANCHO_VENTANA / 2;
				camera.y = ( jugador.getPosY() + Jugador::ALTO_JUGADOR / 2 ) - ALTO_VENTANA / 2;

				//Keep the camera in bounds
				if( camera.x < 0 )
				{
					camera.x = 0;
				}
				if( camera.y < 0 )
				{
					camera.y = 0;
				}
				if( camera.x > ANCHO_NIVEL - camera.w )
				{
					camera.x = ANCHO_NIVEL - camera.w;
				}
				if( camera.y > ALTO_NIVEL - camera.h )
				{
					camera.y = ALTO_NIVEL - camera.h;
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render background
				texturaCancha.render( 0, 0, &camera,0.0,NULL,SDL_FLIP_NONE,gRenderer );

				//Render objects
				jugador.render( camera.x, camera.y,&texturaJugador,gRenderer);

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
        }
    }
	//Free resources and close SDL
	close();

	return 0;

}
