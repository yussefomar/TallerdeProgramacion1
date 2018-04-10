#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Model/Model_Jugador.h"
#include "Utils/Util_Logger.h"
#include "Model/LTexture.h"
#include "View/View_Jugador.h"
#include "Controller/Controller_Jugador.h"
#include "Model/Model_Pelota.h"
#include "View/View_Pelota.h"
#include "View/View_Cancha.h"
#include <yaml-cpp/yaml.h>


//dimension de pantalla
const int MARGEN = 200;
const int ANCHO_VENTANA = 800;
const int ALTO_VENTANA = 600;
const int CAMARAPOSICIONINICIALX = (ANCHO_NIVEL/2)-(ANCHO_VENTANA/2);
const int CAMARAPOSICIONINICIALY = (ALTO_NIVEL/2)-(ALTO_VENTANA/2);
unsigned short logLevel;
using namespace std;
Util_Logger logger;
//The window we'll be rendering to
SDL_Window* window = NULL;
//The window renderer
SDL_Renderer* gRenderer = NULL;

/**

 EL CÓDIGO QUE SIGUE ES MERAMENTE UN EJEMPLO DONDE ESTABA PROBANDO.-
 EJEMPLO PARA LEER LAS KEY Y ARMAR LA VENTANA CON SDL.
 EN PROGRESO, TOMARLO SOLO COMO UN EJEMPLO A MEDIO CAMINO.-

 PARA QUE COMPILE SDL TIENEN QUE AGREGAR EN Project -> Build Options -> Linker Setting -> Other Linker Options:

 -lSDL2

**/
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

void close()
{

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

    Pelota pelota;
    View_Pelota vistaPelota(&pelota,gRenderer);
    Jugador jugador;
    View_Jugador vistaJugador(&jugador,gRenderer);
    Controller_Jugador controlJugador(&jugador,&vistaJugador);
    Jugador jugador2;
    jugador2.setCasacaAlternativa();
    jugador2.setPosX(700);
    jugador2.setPosY(400);
    View_Jugador vistaJugador2(&jugador2,gRenderer);
    Jugador jugador3;
    jugador3.setPosX(700);
    jugador3.setPosY(600);
    View_Jugador vistaJugador3(&jugador3,gRenderer);
    Jugador jugador4;
    jugador4.setPosX(700);
    jugador4.setPosY(800);
    View_Jugador vistaJugador4(&jugador4,gRenderer);
    View_Cancha vistaCancha(gRenderer);
    //The camera area
    SDL_Rect camera = { CAMARAPOSICIONINICIALX,CAMARAPOSICIONINICIALY, ANCHO_VENTANA, ALTO_VENTANA };
    //SDL events
    SDL_Event e;

    bool quit = false;

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
					controlJugador.handleEvent( e );
				}
                //Move the dot
				jugador.move();
				pelota.move();

				//Center the camera over the dot
                if ( (camera.x + ANCHO_VENTANA-MARGEN)<(jugador.getPosX()+Jugador::ANCHO_JUGADOR / 2 )){
				camera.x +=Jugador::VELOCIDAD_JUGADOR; //=( jugador.getPosX() + Jugador::ANCHO_JUGADOR / 2 ) - ANCHO_VENTANA/ 2;
				}
				 if ( (camera.x +MARGEN)>(jugador.getPosX()+Jugador::ANCHO_JUGADOR / 2 )){
				camera.x -=Jugador::VELOCIDAD_JUGADOR;// ( jugador.getPosX() + Jugador::ANCHO_JUGADOR / 2 ) - ANCHO_VENTANA/ 2;
				}

				if ((camera.y + ALTO_VENTANA-MARGEN)<(jugador.getPosY()+Jugador::ALTO_JUGADOR / 2 )){
				camera.y +=Jugador::VELOCIDAD_JUGADOR;//= ( jugador.getPosY() + Jugador::ALTO_JUGADOR / 2 ) - ALTO_VENTANA / 2;
                }
                if ((camera.y +MARGEN)>(jugador.getPosY()+Jugador::ALTO_JUGADOR / 2 )){
				camera.y -=Jugador::VELOCIDAD_JUGADOR;//= ( jugador.getPosY() + Jugador::ALTO_JUGADOR / 2 ) - ALTO_VENTANA / 2;
                }
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
				vistaCancha.render(&camera,gRenderer);
				//texturaCancha.render( 0, 0, &camera,0.0,NULL,SDL_FLIP_NONE,gRenderer );

				vistaPelota.render(camera.x, camera.y,gRenderer);

				//Render objects
                vistaJugador2.render( camera.x, camera.y,gRenderer);

                vistaJugador3.render( camera.x, camera.y,gRenderer);

                vistaJugador4.render( camera.x, camera.y,gRenderer);

                vistaJugador.render( camera.x, camera.y,gRenderer);

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
    }

	//Free resources and close SDL
	close();

	return 0;

}
