#ifndef MODEL_H
#define MODEL_H

#include "../Model/Model_Pelota.h"
#include "../Model/Model_Jugador.h"
#include "../Command/Command.h"
#include "../Model/Formacion.h"
#include "../Utils/Util_Subject.h"

#include <queue>

class Model : public Util_Subject
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

     /*servicios del Modelo en online*/
    virtual void aumentarVelocidadEnX(char codigoJugador);
    virtual void disminuirVelocidadY(char codigojugador);
    virtual void aumentarVelocidadEnY(char codigojugador);
    virtual void disminuirVelocidadX(char codigojugador);
    virtual void desacelerar(char codigojugador);
    virtual void patearPelota(char codigojugador);
    virtual void recuperaPelota(char codigojugador);
    virtual void stopJugador(char codigojugador);
    virtual void acelerar(char codigojugador);
    //agrego y uso IObserver porque es lo que hay
//    virtual void agregarObservador(IObserver* observador);
//    virtual void notificarAObservadores(char entidad, char evento);

    virtual void update();

    virtual void moverJuego();


protected:

private:
    Pelota pelota;
    Jugador* jugadores;
    Jugador* jugadoresVisitantes;
    Formacion *formacion;
    Formacion *formacionVisitante;
    bool juegoIniciado;
    std::string casacaSprite; // TEMPORAL.
    SDL_Rect * camara;
    unsigned int nroJugadorActivo;
    std::queue<Command*> cambios;
    //std::list<IObservaor*> observadores;
};

#endif // MODEL_H
