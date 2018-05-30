#ifndef VIEW_JUGADOR_H_
#define VIEW_JUGADOR_H_

#include <SDL2/SDL.h>

#include "../Model/LTexture.h"
#include "../Model/Model_Jugador.h"
#include "../Utils/Util_LoggerSubject.h"

#define CANTSPRITECLIP 14
#define MINFRAMECAMINA 4
#define MAXFRAMECAMINA 16
#define MINFRAMEACELE 12
#define MAXFRAMEACELE 28
#define MINFRAMEPATEPELO 32
#define MAXFRAMEPATEPELO 36
#define MAXSPRITEUTILIZADO 9
#define DESACTIVARRETARDO 0
#define TIEMPORETARDO 1000

class View_Jugador : public Util_LoggerSubject
{
public:

    View_Jugador( Jugador *model);
    View_Jugador();

    void initialize(Jugador *model,SDL_Renderer * gRenderer,LTexture * texturaJugador,LTexture * texturaSeleccionado);
    void SetModel( Jugador *model);
    void render( int camX, int camY,SDL_Renderer * gRenderer );
    void renderEnEspera( int camX, int camY,SDL_Renderer * gRenderer );
    bool enEspera();


private:
    Jugador *model;
    LTexture * texturaJugador;
    LTexture * texturaSeleccionado;
    int frame = 4;
    double direccion;
    SDL_Rect gSpriteClips[ CANTSPRITECLIP];
    int retardo=0;
};

#endif
