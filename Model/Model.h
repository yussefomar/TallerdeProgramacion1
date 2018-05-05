#ifndef MODEL_H
#define MODEL_H

#include "../Model/Model_Pelota.h"
#include "../Model/Model_Jugador.h"
#include "../Controller/Command.h"
#include "../Model/Formacion.h"
#include "../Utils/Util_LoggerSubject.h"

#include <list>

class Model : public Util_LoggerSubject
{
public:
    Model();
    virtual ~Model();

    /*Datos del Modelo*/
    Pelota* getPelota();
    Jugador* getJugadorNro(int i);
    Jugador* getJugadorActivo();
    std::string  getCasaca();
    void setCamara(SDL_Rect * camara);
    void setFormacion(Formacion* formacion);
    void setCasaca(std::string casacaName);

    /*Servicios del Modelo*/
    void addCommand(Command* command);

    void aumentarVelocidadJugadorActivoEnX();
    void aumentarVelocidadJugadorActivoEnY();
    void disminuirVelocidadJugadorActivoEnX();
    void disminuirVelocidadJugadorActivoEnY();

    void cambiarJugadorActivo();
    void update();


protected:

private:
    Pelota pelota;
    Jugador* jugadores;
    std::string casacaSprite; // TEMPORAL.
    SDL_Rect * camara;
    int nroJugadorActivo;
    std::list<Command*> commandsToApply;
};

#endif // MODEL_H
