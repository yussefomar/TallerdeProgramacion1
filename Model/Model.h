#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include "../Model/Model_Pelota.h"
#include "../Model/Model_Jugador.h"
#include "../Command/Command.h"
#include "../Model/Formacion.h"
#include "../Utils/Util_LoggerObserver.h"
#include <queue>

class Model
{
public:
    Model();
    virtual ~Model();

    /*Datos del Modelo*/
    virtual Pelota* getPelota();
    virtual Jugador* getJugadorNro(int i);
    virtual Jugador* getJugadorVisitanteNro(int i);
    virtual Jugador* getJugadorActivo();
    virtual std::string  getCasaca();
    virtual void setCamara(SDL_Rect * camara);
    virtual void setFormacionLocal(Formacion* formacion);
    virtual void setFormacionVisitante(Formacion* formacion);
    virtual void setCasaca(std::string casacaName);
    //virtual void setIp(std::string ipName); va a ser un string???
    virtual char getCodigoJugadorActivo();
    virtual void setPelotaEnMovimiento();
    virtual void setPelotaParada();
    virtual bool pelotaEnMovimiento();

    /*Servicios del Modelo en modo Offline*/
    virtual void agregarCambio(Command* cambio);
    virtual void jugadorActivoAumentaVelocidadEnX();
    virtual void jugadorActivoAumentaVelocidadEnY();
    virtual void jugadorActivoDisminuyeVelocidadEnX();
    virtual void jugadorActivoDisminuyeVelocidadEnY();
    virtual void jugadorActivoAcelera();
    virtual void jugadorActivoDesacelera();
    virtual void jugadorActivoPateaPelota();
    virtual void jugadorActivoRecuperaPelota();
    virtual void jugadorActivoDetener();
    virtual void jugadorActivoCambia();
    virtual void jugadorActivoPasaPelota();

    /*servicios del Modelo en online*/
    void aumentarVelocidadEnX(unsigned codigoJugador);
    void disminuirVelocidadY(unsigned codigoJugador);
    void aumentarVelocidadEnY(unsigned codigoJugador);
    void disminuirVelocidadX(unsigned codigoJugador);
    void desacelerar(unsigned codigoJugador);
    void patearPelota(unsigned codigoJugador);
    void recuperaPelota(unsigned codigoJugador);
    void stopJugador(unsigned codigoJugador);
    void acelerar(unsigned codigoJugador);
    void cambiarDeJugador(unsigned codigoJugador);
    void pasaPelota(unsigned codigojugador);

    void agregarObservador(Util_LoggerObserver* obs);
    void notificarAObservadores(unsigned entidad, char evento, char tipo);
    void quitarObservador(Util_LoggerObserver* obs);

    virtual void update();

    virtual void moverJuego();


protected:

private:
    Pelota pelota;
    //Jugador* jugadores;
    Jugador* jugadoresEnCancha;
    Jugador* jugadoresLocales;
    Jugador* jugadoresVisitantes;
    Formacion* formacion;
    //Formacion *formacionLocales;
    Formacion *formacionVisitante;
    bool juegoIniciado;
    std::string casacaSprite; // TEMPORAL.
    SDL_Rect * camara;
    unsigned int nroJugadorActivo;
    std::queue<Command*> cambios;
    std::vector<Util_LoggerObserver*> observadores;

};

#endif // MODEL_H
