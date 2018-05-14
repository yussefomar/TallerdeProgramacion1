#ifndef VIEW_LOGUIN_H_
#define VIEW_LOGUIN_H_

//The headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

using namespace std;

//Manejador de lo que se ingresa por teclado
class View_Loguin
{
    public:
    //Constructor
    View_Loguin(int i);
    //Destructor
    ~View_Loguin();
    //Procesamos la información.
    std::string Procesar(std::string mensajeError);
};

#endif /* VIEW_LOGUIN_H_ */
