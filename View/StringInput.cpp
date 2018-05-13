/**
//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

using namespace std;

#include "../View/StringInput.h"

//The color of the font
SDL_Color inputTextColor = { 0xFF, 0xFF, 0xFF };
//The event structure
SDL_Event inputEvent;
TTF_Font *inputFont = NULL;

StringInput::StringInput(int i)
{
    //Initialize the string
    str = "";

    //Initialize the surface
    text = NULL;

    inputFont == TTF_OpenFont( "../Images/respuesta.otf", 35 );

    //Enable Unicode
    SDL_EnableUNICODE( SDL_ENABLE );
}

StringInput::~StringInput()
{
    //Free text surface
    SDL_FreeSurface( text );
    //
    //TTF_CloseFont( inputFont );

    //Disable Unicode
    SDL_EnableUNICODE( SDL_DISABLE );
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
            if( inputEvent.key.keysym.unicode == (Uint16)' ' )
            {
                //Append the character
                str += (char)inputEvent.key.keysym.unicode;
            }
            //If the key is a number
            else if( ( inputEvent.key.keysym.unicode >= (Uint16)'0' ) && ( inputEvent.key.keysym.unicode <= (Uint16)'9' ) )
            {
                //Append the character
                str += (char)inputEvent.key.keysym.unicode;
            }
            //If the key is a uppercase letter
            else if( ( inputEvent.key.keysym.unicode >= (Uint16)'A' ) && ( inputEvent.key.keysym.unicode <= (Uint16)'Z' ) )
            {
                //Append the character
                str += (char)inputEvent.key.keysym.unicode;
            }
            //If the key is a lowercase letter
            else if( ( inputEvent.key.keysym.unicode >= (Uint16)'a' ) && ( inputEvent.key.keysym.unicode <= (Uint16)'z' ) )
            {
                //Append the character
                str += (char)inputEvent.key.keysym.unicode;
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
**/
