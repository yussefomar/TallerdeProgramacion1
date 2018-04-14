#ifndef MODEL_H
#define MODEL_H

#include "Model_Pelota.h"
#include "Model_Jugador.h"
#include "Command.h"

#include <list>

class Model
{
public:
    Model();
    virtual ~Model();
    Pelota* getPelota();
    Jugador* getJugadorNro(int i);
    Jugador* getJugadorActivo();
    void addCommand(Command* command);
    void cambiarJugadorActivo();
    void detenerJugadores();
    void update();
    void setCamara(SDL_Rect * camara);

protected:

private:
    Pelota pelota;
    Jugador* jugadores;
    Jugador jugadorActual;
    SDL_Rect * camara;
    int nroJugadorActivo;
    std::list<Command*> commandsToApply;
};

#endif // MODEL_H
