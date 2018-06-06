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
    void aumentarVelocidadEnX(char codigoCliente);
    void disminuirVelocidadY(char codigoCliente);
    void aumentarVelocidadEnY(char codigoCliente);
    void disminuirVelocidadX(char codigoCliente);
    void desacelerar(char codigoCliente);
    void patearPelota(char codigoCliente);
    void recuperaPelota(char codigoCliente);
    void stopJugador(char codigoCliente);
    void acelerar(char codigoCliente);
    void cambiarDeJugador(char codigoCliente);
    void pasarPelota(char codigoCliente);

    void agregarObservador(Observador* obs);
    void notificarAObservadores(unsigned entidad, char evento, char tipo);
    void quitarObservador(Observador* obs);

    virtual void update();

    virtual void moverJuego();

    /*Seteos del cliente en modo online*/
    void setIdCliente(char id);
    char getIdCliente();
    void setTodosJugadoresInactivos();
    void definirComoLocal(char codigoCliente);
    void definirComoVisitante(char codigoCliente);
    void desconectarCliente(char codigoCliente);
    void habilitarRender();
    bool necesitaRenderizar();
    void setCantidadClientes(unsigned cantidad);
    std::string armarBackUp();
    void desarmarBackUp(std::string str);
    void comenzarAArmarBackup();
    void comemnzarADesarmarBackup();

    std::string backupTrucha;

protected:

private:
    Pelota pelota;
    Jugador* jugadoresEnCancha;
    Jugador* jugadoresLocales;
    Jugador* jugadoresVisitantes;
    Formacion* formacion;
    Formacion* formacionVisitante;
    bool juegoIniciado;
    std::string casacaSprite; // TEMPORAL.
    SDL_Rect * camara;
    unsigned int nroJugadorActivo;
    std::queue<Command*> cambios;
    std::vector<Observador*> observadores;
    std::vector<unsigned> clientes; //asocia el id de los clientes conectados con el jugador que controlan
    char idCliente;
    unsigned cantidadLocales;
    unsigned cantidadVisitantes;
    unsigned cantidadClientes;
    bool renderizar;
    std::string bakcup;

};

#endif // MODEL_H
