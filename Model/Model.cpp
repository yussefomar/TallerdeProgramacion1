#include "../Model/Model.h"
#include "../View/ViewModel.h"
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <iostream>
#include <string>

#define CANTJUGADORESTOTALES 14
#define CANTJUGADORES 7


Model::Model()
{
    this->jugadores = new Jugador[CANTJUGADORESTOTALES]();
    this->jugadoresLocales = this->jugadores;
    this->jugadoresVisitantes = this->jugador
    this->nroJugadorActivo = 6;
    this->getJugadorActivo()->activar();
    this->juegoIniciado=false;
}

Model::~Model()
{
    delete[] this->jugadores;
}

Pelota* Model::getPelota()
{
    return &(this->pelota);
}

Jugador* Model::getJugadorNro(int i)
{
    return &(this->jugadores[i]);
}

Jugador* Model::getJugadorVisitanteNro(int i)
{
    return &(this->jugadoresVisitantes[i]);
}

Jugador* Model::getJugadorActivo()
{
    return &(this->jugadores[this->nroJugadorActivo]);
}

void Model::agregarCambio(Command* cambio)
{


    this->cambios.push(cambio);


}

void Model::jugadorActivoCambia()
{


    unsigned i = this->nroJugadorActivo+1;
    if (i == CANTJUGADORES)
    {
        i= 0;
    }
    bool encontrado = false;
    while ((i != this->nroJugadorActivo) && !encontrado)
    {
        if ((this->jugadores[i].collide(this->camara )) && (this->nroJugadorActivo!=i))
        {
            (this->jugadores[(this->nroJugadorActivo)]).desactivar();
            (this->jugadores[i]).activar();
            this->nroJugadorActivo = i;
            encontrado = true;
            this->notificarAObservadores(i, COMMNULL, MJU);
        }
        ++i;
        if (i == CANTJUGADORES)
        {
            i= 0;
        }
    }
}

void Model::update()
{



    if(!this->cambios.empty())
    {
        Command* cambio = this->cambios.front();
        cambio->execute();
        this->cambios.pop();
    }


    for(int i = 0; i < CANTJUGADORES; ++i)
    {
        this->jugadores[i].move();
        this->jugadoresVisitantes[i].move();
    }
    this->pelota.move();



}

void Model::moverJuego()
{
    for(int i = 0; i < CANTJUGADORES; ++i)
    {
        this->jugadores[i].move();
        this->jugadoresVisitantes[i].move();
    }
    this->pelota.move();
}

void Model::setCamara(SDL_Rect * camara)
{

    this->camara = camara;
    this->notificarAObservadores(0, COMMNULL, MSJ);

}

void Model::setFormacionLocal(Formacion* formacion)
{

    this->formacion= formacion;
    this->formacion->setPosicionInicialLocal(this->jugadores);
    this->notificarAObservadores(0, COMMNULL, MSJ);
}

void Model::setFormacionVisitante(Formacion* formacion)
{

    this->formacionVisitante= formacion;
    this->formacionVisitante->setPosicionInicialVisitante(this->jugadoresVisitantes);
    this->notificarAObservadores(0, COMMNULL, MSJ);

}


void Model::setPelotaParada()
{
    this->juegoIniciado= false;
}

void Model::setPelotaEnMovimiento()
{
    this->formacionVisitante->setPosicionVisitante(this->jugadoresVisitantes);
    this->formacion->setPosicionLocal(this->jugadores);
    this->juegoIniciado= true;
}

bool Model::pelotaEnMovimiento()
{
    return this->juegoIniciado;

}

void Model::setCasaca(std::string casacaName)
{


    char c1[100];
    for(unsigned i = 0; i<casacaName.size(); i++)
    {
        casacaName.at(i) = toupper(casacaName.at(i));
        c1[i] = casacaName.at(i);
    }
    char c3[] = "suplente";

    if((strncasecmp(c1,c3,2))==0)
    {
        for(int i = 0; i < CANTJUGADORES; ++i)
        {
            this->jugadores[i].setCasacaAlternativa();
        }
    }
    else
    {

        for(int i = 0; i < CANTJUGADORES; ++i)
        {
            this->jugadoresVisitantes[i].setCasacaAlternativa();
            this->notificarAObservadores(i, COMMNULL, MJU);
        }
    }


}

std::string Model::getCasaca()
{
    return this->casacaSprite;
}

char Model::getCodigoJugadorActivo()
{
    /*Esto debe adecuarse al momento de tener equipos
    y seguir usando char*/
    char codigo = 0x00;
    return (codigo + this->nroJugadorActivo);
}

void Model::jugadorActivoAumentaVelocidadEnX()
{
    this->jugadores[this->nroJugadorActivo].aumentarVelocidadX();
    this->notificarAObservadores(this->nroJugadorActivo, INCVELX, MJU);
}

void Model::jugadorActivoAumentaVelocidadEnY()
{
    this->jugadores[this->nroJugadorActivo].aumentarVelocidadY();
    this->notificarAObservadores(this->nroJugadorActivo, INCVELY, MJU);
}

void Model::jugadorActivoDisminuyeVelocidadEnX()
{
    this->jugadores[this->nroJugadorActivo].disminuirVelocidadX();
    this->notificarAObservadores(this->nroJugadorActivo, DECVELX, MJU);
}


void Model::jugadorActivoDisminuyeVelocidadEnY()
{
    this->jugadores[this->nroJugadorActivo].disminuirVelocidadY();
    this->notificarAObservadores(this->nroJugadorActivo, DECVELY, MJU);
}

void Model::jugadorActivoAcelera()
{
    this->jugadores[this->nroJugadorActivo].acelerar();
    this->notificarAObservadores(this->nroJugadorActivo, ACCJUG, MJU);
}

void Model::jugadorActivoDesacelera()
{
    this->jugadores[this->nroJugadorActivo].desacelerar();
    this->notificarAObservadores(this->nroJugadorActivo, DESJUG, MJU);
}

void Model::jugadorActivoPateaPelota()
{
    this->jugadores[this->nroJugadorActivo].patearPelota(&(this->pelota));
    this->notificarAObservadores(this->nroJugadorActivo, PATPELO, MJU);
}

void Model::jugadorActivoRecuperaPelota()
{
    this->jugadores[this->nroJugadorActivo].recuperaPelota(&(this->pelota));
    this->notificarAObservadores(this->nroJugadorActivo, RECUPELO, MJU);
}

void Model::jugadorActivoDetener()
{
    this->jugadores[this->nroJugadorActivo].detenerVelocidad();
    this->notificarAObservadores(this->nroJugadorActivo, STOPJUG, MJU);
}

/*Servicios del modelo en modo online*/
void Model::aumentarVelocidadEnX(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].aumentarVelocidadX();
    this->notificarAObservadores(nrojugador, INCVELX, MJU);
}

void Model::aumentarVelocidadEnY(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].aumentarVelocidadY();
    this->notificarAObservadores(nrojugador, INCVELY, MJU);
}

void Model:: disminuirVelocidadY(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].disminuirVelocidadY();
    this->notificarAObservadores(nrojugador, DECVELY, MJU);
}

void Model:: disminuirVelocidadX(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].disminuirVelocidadX();
    this->notificarAObservadores(nrojugador, DECVELX, MJU);
}

void Model:: desacelerar(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].desacelerar();
    this->notificarAObservadores(nrojugador, DESJUG, MJU);
}

void Model:: patearPelota(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].patearPelota(this->getPelota());
    this->notificarAObservadores(nrojugador, PATPELO, MJU);;
}

void Model:: recuperaPelota(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].recuperaPelota(this->getPelota());
    this->notificarAObservadores(nrojugador, RECUPELO, MJU);
}

void Model:: stopJugador(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].detenerVelocidad();
    this->notificarAObservadores(nrojugador, STOPJUG, MJU);
}

void Model::acelerar(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].acelerar();
    this->notificarAObservadores(nrojugador, ACCJUG, MJU);
}
void Model::agregarObservador(Util_LoggerObserver* observador)
{
    this->observadores.push_back(observador);
}

void Model::notificarAObservadores(unsigned entidad, char evento, char tipo)
{
    for(std::vector<Util_LoggerObserver*>::const_iterator iter = observadores.begin(); iter != observadores.end(); ++iter)
    {
        (*iter)->notificar(std::to_string(entidad), evento, tipo);
    }

}

void Model::quitarObservador(Util_LoggerObserver* obs)
{
    this->observadores.erase(std::remove(observadores.begin(), observadores.end(), obs), observadores.end());
}




