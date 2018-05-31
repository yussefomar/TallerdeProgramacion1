#ifndef STRINGINPUT_H_
#define STRINGINPUT_H_

//The headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

using namespace std;

//Manejador de lo que se ingresa por teclado
class StringInput
{
public:
    //Mensaje que se almacena
    std::string str;
    //Constructor
    StringInput(std::string data);
    //Destructor
    ~StringInput();
    //Manejador de los eventos
    void handle_input(SDL_Event inputEvent);
};

#endif /* STRINGINPUT_H_ */
