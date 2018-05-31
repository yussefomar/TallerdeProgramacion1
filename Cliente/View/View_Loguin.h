#ifndef VIEW_LOGUIN_H_
#define VIEW_LOGUIN_H_

//The headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "../View/InformacionIngreso.h"

using namespace std;

//Manejador de lo que se ingresa por teclado
class View_Loguin
{
public:
    //Constructor
    View_Loguin(int i);
    //Destructor
    ~View_Loguin();
    //Inicializamos los elementos básico de la pantalla.
    bool Inicializar();
    //Procesamos la información.
    void Procesar(InformacionIngreso &informacionIngreso);
    //Cerramos y destruimos todo lo relacionado a la pantalla.
    void Cerrar();
};

#endif /* VIEW_LOGUIN_H_ */
