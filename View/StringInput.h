/**
//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

using namespace std;

//Manejador de lo que se ingresa por teclado
class StringInput
{
    public:
    //Mensaje que se almacena
    std::string str;
    //Texto SDL
    SDL_Surface *text;
    //Font para lo que ingresa el usuario
    TTF_Font *inputFont;
    //Constructor
    StringInput(int i);
    //Destructor
    ~StringInput();

    //Manejador de los eventos
    void handle_input(SDL_Event inputEvent);
};

**/
