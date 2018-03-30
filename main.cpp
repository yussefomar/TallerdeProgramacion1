#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdio.h>

#include "Utils/Util_Logger.h"

using namespace std;

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

void inicializar()
{
    for(int i = 0; i < 322; i++)
    {
        // init them all to false
        KEYS[i] = false;
    }
    // you can configure this how you want,
    // but it makes it nice for when you want to register a key continuously being held down
    //SDL_EnableKeyRepeat(0,0);
}

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

int main(int argc, char* args[])
{

	/********************************************************************************************/
	// Inicializar el log.
	logger.createFile(3);

	//Si queremos usar el logger mientras leemos el archivo de configuracion debemos crearlo como
	//arriba, luego podemos llamar al método updateLevel para ponerle el nivel que corresponda.

    //En cualquier parte del código que querramos usar el logger podemos llamar a los siguientes
    //métodos según corresponda, luego según el level del logger, escribirá o no en el archivo.
    //por ejemplo en un catch donde saltó una excepción ponemos log.writeErrorLine y si el level
    //está configurado para escribir errores los pondra en el archivo.
	logger.writeErrorLine("Ejemplo de Error."); //nivel bajo, siempre mostramos errores.
	logger.writeWarningLine("Ejemplo de Warning."); //nivel medio, mostramos errores y warnings.
	logger.writeLine("Ejemplo de linea común."); //nivel alto, se escribe todo.
	/********************************************************************************************/

	/********************************************************************************************/
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Hello",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,  SDL_WINDOW_SHOWN);
    SDL_Event e;
    int quit=0;
    inicializar();
    /*while(true)//(KEYS[SDLK_UP])
    {
        // do something
        // keyboard();
        // don't forget to redetect which keys are being pressed!
        // handleInput();
    }*/
    return 0;
}
