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
    //this->jugadores = new Jugador[CANTJUGADORESTOTALES]();
    //this->jugadoresLocales = this->jugadores;
    //this->jugadoresVisitantes = &(this->jugadores[7]);
    this->jugadoresEnCancha = new Jugador[CANTJUGADORESTOTALES];
    this->jugadoresLocales = this->jugadoresEnCancha;
    this->jugadoresVisitantes = &(this->jugadoresEnCancha[7]);
    this->nroJugadorActivo = 6;
    this->getJugadorActivo()->activar();
    this->juegoIniciado=false;
}

Model::~Model()
{
    delete[] this->jugadoresEnCancha;
}

Pelota* Model::getPelota()
{
    return &(this->pelota);
}

Jugador* Model::getJugadorNro(int i)
{
    return &(this->jugadoresEnCancha[i]);
}

Jugador* Model::getJugadorVisitanteNro(int i)
{
    return &(this->jugadoresVisitantes[i]);
}

Jugador* Model::getJugadorActivo()
{
    return &(this->jugadoresEnCancha[this->nroJugadorActivo]);
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
        if ((this->jugadoresLocales[i].collide(this->camara )) && (this->nroJugadorActivo!=i))
        {
            (this->jugadoresLocales[(this->nroJugadorActivo)]).desactivar();
            (this->jugadoresLocales[i]).activar();
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
    this->moverJuego();
}

void Model::moverJuego()
{
    for(int i = 0; i < CANTJUGADORESTOTALES; ++i)
    {
        this->jugadoresEnCancha[i].move();
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
    this->formacion->setPosicionInicialLocal(this->jugadoresLocales);
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
    this->formacion->setPosicionLocal(this->jugadoresLocales);
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
            this->jugadoresLocales[i].setCasacaAlternativa();
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
    return this->casacaSprite;//sigue funcionando ahora que no existe un solo equipo?
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
    this->jugadoresLocales[this->nroJugadorActivo].aumentarVelocidadX();
    this->notificarAObservadores(this->nroJugadorActivo, INCVELX, MJU);
}

void Model::jugadorActivoAumentaVelocidadEnY()
{
    this->jugadoresLocales[this->nroJugadorActivo].aumentarVelocidadY();
    this->notificarAObservadores(this->nroJugadorActivo, INCVELY, MJU);
}

void Model::jugadorActivoDisminuyeVelocidadEnX()
{
    this->jugadoresLocales[this->nroJugadorActivo].disminuirVelocidadX();
    this->notificarAObservadores(this->nroJugadorActivo, DECVELX, MJU);
}


void Model::jugadorActivoDisminuyeVelocidadEnY()
{
    this->jugadoresLocales[this->nroJugadorActivo].disminuirVelocidadY();
    this->notificarAObservadores(this->nroJugadorActivo, DECVELY, MJU);
}

void Model::jugadorActivoAcelera()
{
    this->jugadoresLocales[this->nroJugadorActivo].acelerar();
    this->notificarAObservadores(this->nroJugadorActivo, ACCJUG, MJU);
}

void Model::jugadorActivoDesacelera()
{
    this->jugadoresLocales[this->nroJugadorActivo].desacelerar();
    this->notificarAObservadores(this->nroJugadorActivo, DESJUG, MJU);
}

void Model::jugadorActivoPateaPelota()
{
    this->jugadoresLocales[this->nroJugadorActivo].patearPelota(&(this->pelota));
    this->notificarAObservadores(this->nroJugadorActivo, PATPELO, MJU);
}

void Model::jugadorActivoPasaPelota()
{
    unsigned i = this->nroJugadorActivo+1;
    if (i == CANTJUGADORES)
    {
        i= 0;
    }
    bool encontrado = false;
    while ((i != this->nroJugadorActivo) && !encontrado)
    {
        if ((this->jugadoresLocales[i].collide(this->camara )) && (this->nroJugadorActivo!=i))
        {
            encontrado = true;
        }
        if (i == CANTJUGADORES)
        {
            i= 0;
        }
        if (!encontrado){
        i++;
        }
    }
    if (encontrado){
        this->jugadoresLocales[this->nroJugadorActivo].pasaPelota(&(this->pelota),&this->jugadoresLocales[i] );
        this->notificarAObservadores(this->nroJugadorActivo, PASPELO, MJU);
    }
}

void Model::jugadorActivoRecuperaPelota()
{
    Jugador activoPrevio =this->jugadoresLocales[this->nroJugadorActivo];
    if (this->jugadoresLocales[this->nroJugadorActivo].recuperaPelota(&(this->pelota))){
        activoPrevio.noPoseePelota();
    }
    this->notificarAObservadores(this->nroJugadorActivo, RECUPELO, MJU);
}

void Model::jugadorActivoDetener()
{
    this->jugadoresLocales[this->nroJugadorActivo].detenerVelocidad();
    this->notificarAObservadores(this->nroJugadorActivo, STOPJUG, MJU);
}

/*Servicios del modelo en modo online*/

void Model::aumentarVelocidadEnX(unsigned codigoJugador)
{
    this->jugadoresEnCancha[codigoJugador].aumentarVelocidadX();
    this->notificarAObservadores(codigoJugador, INCVELX, MJU);
}

void Model::aumentarVelocidadEnY(unsigned codigoJugador)
{
    this->jugadoresEnCancha[codigoJugador].aumentarVelocidadY();
    this->notificarAObservadores(codigoJugador, INCVELY, MJU);
}

void Model:: disminuirVelocidadY(unsigned codigoJugador)
{
    this->jugadoresEnCancha[codigoJugador].disminuirVelocidadY();
    this->notificarAObservadores(codigoJugador, DECVELY, MJU);
}

void Model:: disminuirVelocidadX(unsigned codigoJugador)
{
    this->jugadoresEnCancha[codigoJugador].disminuirVelocidadX();
    this->notificarAObservadores(codigoJugador, DECVELX, MJU);
}

void Model:: desacelerar(unsigned codigoJugador)
{
    this->jugadoresEnCancha[codigoJugador].desacelerar();
    this->notificarAObservadores(codigoJugador, DESJUG, MJU);
}

void Model:: patearPelota(unsigned codigoJugador)
{
    this->jugadoresEnCancha[codigoJugador].patearPelota(this->getPelota());
    this->notificarAObservadores(codigoJugador, PATPELO, MJU);;
}

void Model:: recuperaPelota(unsigned codigoJugador)
{
    this->jugadoresEnCancha[codigoJugador].recuperaPelota(this->getPelota());
    this->notificarAObservadores(codigoJugador, RECUPELO, MJU);
}

void Model:: pasaPelota(unsigned codigoJugador)
{
  /*
    unsigned i = codigoJugador+1;
    if (i == CANTJUGADORES)
    {
        i= 0;
    }
    bool encontrado = false;
    while ((i != codigoJugador) && !encontrado)
    {
        if ((this->jugadores[i].collide(this->camara )) && (codigoJugador!=i))
        {
            (this->jugadores[codigoJugador]).desactivar();
            (this->jugadores[i]).activar();
            this->nroJugadorActivo = i;
            encontrado = true;
        }
        if (i == CANTJUGADORES)
        {
            i= 0;
        }
        if (!encontrado) {
        i++;
        }
    }

    this->jugadores[codigoJugador].pasaPelota(this->getPelota(),&this->jugadores[i]);
    //this->notificarAObservadores(codigoJugador, RECUPELO, MJU);*/
}

void Model::stopJugador(unsigned codigoJugador)
{
    this->jugadoresEnCancha[codigoJugador].detenerVelocidad();
    this->notificarAObservadores(codigoJugador, STOPJUG, MJU);
}

void Model::acelerar(unsigned codigoJugador)
{
    this->jugadoresEnCancha[codigoJugador].acelerar();
    this->notificarAObservadores(codigoJugador, ACCJUG, MJU);
}

void Model::cambiarDeJugador(unsigned codigoJugador) {
    return ;
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




