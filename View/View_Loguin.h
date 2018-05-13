/**
//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
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
    //Procesamos la llamada del loguin
    //devolvemos un string con lo ingresado por el usuario
    std::string procesar();
};
**/
