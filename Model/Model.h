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
    virtual Pelota* getPelota();
    virtual Jugador* getJugadorNro(int i);
    virtual Jugador* getJugadorActivo();
    virtual std::string  getCasaca();
    virtual void setCamara(SDL_Rect * camara);
    virtual void setFormacion(Formacion* formacion);
    virtual void setCasaca(std::string casacaName);

    /*Servicios del Modelo*/
    virtual void addCommand(Command* command);
    virtual void jugadorActivoAumentaVelocidadEnX();
    virtual void jugadorActivoAumentaVelocidadEnY();
    virtual void jugadorActivoDisminuyeVelocidadEnX();
    virtual void jugadorActivoDisminuyeVelocidadEnY();
    virtual void jugadorActivoAcelera();
    virtual void jugadorActivoDesacelera();
    virtual void jugadorActivoPateaPelota();
    virtual void jugadorActivoRecuperaPelota();
    virtual void jugadorActivoDetener();
    virtual void cambiarJugadorActivo();
    virtual void update();


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
