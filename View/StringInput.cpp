//The headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

using namespace std;

#include "../View/StringInput.h"

//The color of the font
SDL_Color inputTextColor = { 0xFF, 0xFF, 0xFF };
//The event structure
SDL_Event inputEvent;

StringInput::StringInput(std::string data)
{
    //Initialize the string
    this->str = data;
}

StringInput::~StringInput()
{

    //TTF_CloseFont( inputFont );
}

void StringInput::handle_input(SDL_Event inputEvent)
{
    //If a key was pressed
    if( inputEvent.type == SDL_KEYDOWN )
    {
        //If the string less than maximum size
        if( str.length() <= 16 )
        {
            //If the key is a space
            if( inputEvent.key.keysym.sym == (Uint16)' ' )
            {
                //Append the character
                str += (char)inputEvent.key.keysym.sym;
            }
            //If the key is a number
            else if( ( inputEvent.key.keysym.sym >= (Uint16)'0' ) && ( inputEvent.key.keysym.sym <= (Uint16)'9' ) )
            {
                //Append the character
                str += (char)inputEvent.key.keysym.sym;
            }
            //If the key is a uppercase letter
            else if( ( inputEvent.key.keysym.sym >= (Uint16)'A' ) && ( inputEvent.key.keysym.sym <= (Uint16)'Z' ) )
            {
                //Append the character
                str += (char)inputEvent.key.keysym.sym;
            }
            //If the key is a lowercase letter
            else if( ( inputEvent.key.keysym.sym >= (Uint16)'a' ) && ( inputEvent.key.keysym.sym <= (Uint16)'z' ) )
            {
                //Append the character
                str += (char)inputEvent.key.keysym.sym;
            }
            else if( ( inputEvent.key.keysym.sym == (Uint16)'.' ) || ( inputEvent.key.keysym.sym == (Uint16)':' ) )
            {
                //Append the character
                str += (char)inputEvent.key.keysym.sym;
            }
        }

        //If backspace was pressed and the string isn't blank
        if( ( inputEvent.key.keysym.sym == SDLK_BACKSPACE ) && ( str.length() != 0 ) )
        {
            //Remove a character from the end
            str.erase( str.length() - 1 );
        }
    }
}
