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
#define LOCALES 0
#define VISITANTES 7
#define CANTMAXCLIENTES 4

#define ERR_CON 0x20
#define ERR_ESP 0x21
#define OK_CONTINUA 0x22


Model::Model()
{
    this->jugadoresEnCancha = new Jugador[CANTJUGADORESTOTALES];
    this->jugadoresLocales = &(this->jugadoresEnCancha[LOCALES]);
    this->jugadoresVisitantes = &(this->jugadoresEnCancha[VISITANTES]);
    this->nroJugadorActivo = 6;
    this->getJugadorActivo()->activar();
    this->juegoIniciado=false;
    this->clientes = std::vector<unsigned>(CANTMAXCLIENTES);
    //hiper hardcode para probar...
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i] = i * 2;
    }
    this->idCliente = 0x00;//POR DEFECTO HASTA ESPERAR EL NUEVO ID
    this->cantidadLocales = 0;
    this->cantidadVisitantes = 0;
    this->cantidadClientes = 0;
    this->renderizar = false;
}

Model::~Model()
{
    delete[] this->jugadoresEnCancha;
}

void Model::setIdCliente(char id)
{
    this->idCliente = id;
}

char Model::getIdCliente()
{
    return this->idCliente;
}

Pelota* Model::getPelota()
{
    return &(this->pelota);
}

Jugador* Model::getJugadorNro(int i)
{
    return &(this->jugadoresLocales[i]);
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
            this->notificarAObservadores(i, COMMNULL, MJU);
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
        if (!encontrado)
        {
            i++;
        }
    }
    if (encontrado)
    {
        this->jugadoresLocales[this->nroJugadorActivo].pasaPelota(&(this->pelota),&this->jugadoresLocales[i] );
        this->notificarAObservadores(this->nroJugadorActivo, PASPELO, MJU);
    }
}

void Model::jugadorActivoRecuperaPelota()
{
    Jugador activoPrevio =this->jugadoresLocales[this->nroJugadorActivo];
    if (this->jugadoresLocales[this->nroJugadorActivo].recuperaPelota(&(this->pelota)))
    {
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



void Model::aumentarVelocidadEnX(char codigoCliente)
{
    unsigned nroJugador = this->clientes[codigoCliente];
    this->jugadoresEnCancha[nroJugador].aumentarVelocidadX();
    this->notificarAObservadores(nroJugador, INCVELX, MJU);
}

void Model::aumentarVelocidadEnY(char codigoCliente)
{
    unsigned nroJugador = this->clientes[codigoCliente];

    this->jugadoresEnCancha[nroJugador].aumentarVelocidadY();
    this->notificarAObservadores(nroJugador, INCVELY, MJU);
}

void Model:: disminuirVelocidadY(char codigoCliente)
{
    unsigned nroJugador = this->clientes[codigoCliente];

    this->jugadoresEnCancha[nroJugador].disminuirVelocidadY();
    this->notificarAObservadores(nroJugador, DECVELY, MJU);
}

void Model:: disminuirVelocidadX(char codigoCliente)
{
    unsigned nroJugador = this->clientes[codigoCliente];

    this->jugadoresEnCancha[nroJugador].disminuirVelocidadX();
    this->notificarAObservadores(nroJugador, DECVELX, MJU);
}

void Model:: desacelerar(char codigoCliente)
{
    unsigned nroJugador = this->clientes[codigoCliente];

    this->jugadoresEnCancha[nroJugador].desacelerar();
    this->notificarAObservadores(nroJugador, DESJUG, MJU);
}

void Model:: patearPelota(char codigoCliente)
{
    unsigned nroJugador = this->clientes[codigoCliente];

    this->jugadoresEnCancha[nroJugador].patearPelota(this->getPelota());
    this->notificarAObservadores(nroJugador, PATPELO, MJU);;
}

void Model:: recuperaPelota(char codigoCliente)
{

    unsigned nroJugador = this->clientes[codigoCliente];

    this->jugadoresEnCancha[nroJugador].recuperaPelota(this->getPelota());
    this->notificarAObservadores(nroJugador, RECUPELO, MJU);
}

void Model::stopJugador(char codigoCliente)
{
    unsigned nroJugador = this->clientes[codigoCliente];

    this->jugadoresEnCancha[nroJugador].detenerVelocidad();
    this->notificarAObservadores(nroJugador, STOPJUG, MJU);
}

void Model::acelerar(char codigoCliente)
{
    unsigned nroJugador = this->clientes[codigoCliente];

    this->jugadoresEnCancha[nroJugador].acelerar();
    this->notificarAObservadores(nroJugador, ACCJUG, MJU);
}

void Model::cambiarDeJugador(char codigoCliente)
{
    bool visitante = false;
    unsigned nroJugador = this->clientes[codigoCliente];
    Jugador* vecJugadores = new Jugador[CANTJUGADORES];
    vecJugadores = &(this->jugadoresEnCancha[LOCALES]);
    if (nroJugador > 6 )
    {
        vecJugadores = &(this->jugadoresEnCancha[VISITANTES]);
        nroJugador=nroJugador-7;
        visitante= true;

    }

    unsigned i = nroJugador+1;
    if (i == CANTJUGADORES)
    {
        i= 0;
    }
    bool encontrado = false;
    while ((i != nroJugador) && !encontrado && (!vecJugadores[i].estaActivo()))
    {
        if ((vecJugadores[i].collide(this->camara )) && (nroJugador!=i))
        {
            (vecJugadores[nroJugador]).desactivar();
            (vecJugadores[i]).activar();
            if (visitante)
            {
                this->clientes[codigoCliente] = i + 7;
            }
            else
            {
                this->clientes[codigoCliente] = i;
            }

            this->nroJugadorActivo = i;
            encontrado = true;
            this->notificarAObservadores(i, COMMNULL, MJU);
        }
        if (!encontrado)
        {
            i++;
        }
        if (i == CANTJUGADORES)
        {
            i= 0;
        }
    }
}

void Model::pasarPelota(char codigoCliente)
{
    unsigned nroJugador = this->clientes[codigoCliente];
    Jugador* vecJugadores = new Jugador[CANTJUGADORES];
    vecJugadores = &(this->jugadoresEnCancha[LOCALES]);
    if (nroJugador > 6 )
    {
        vecJugadores = &(this->jugadoresEnCancha[VISITANTES]);
        nroJugador=nroJugador-7;
    }
    if((codigoCliente == 0x00)  && !this->pelotaEnMovimiento())
    {
        this->setPelotaEnMovimiento();
       }

    if(this->pelotaEnMovimiento() ){
        unsigned i = nroJugador+1;
        if (i == CANTJUGADORES)
        {
            i= 0;
        }

        bool encontrado = false;
        while ((i != nroJugador) && !encontrado)
        {
            if ((vecJugadores[i].collide(this->camara )) && (nroJugador!=i))
            {
                encontrado = true;
            }
            if (i == CANTJUGADORES)
            {
                i= 0;
            }
            if (!encontrado)
            {
                i++;
            }
        }
        if (encontrado)
        {
            vecJugadores[nroJugador].pasaPelota(&(this->pelota),&vecJugadores[i] );
            this->notificarAObservadores(nroJugador, PASPELO, MJU);
        }
        }
}


void Model::agregarObservador(Observador* observador)
{
    this->observadores.push_back(observador);
}

void Model::notificarAObservadores(unsigned entidad, char evento, char tipo)
{
    for(std::vector<Observador*>::const_iterator iter = observadores.begin(); iter != observadores.end(); ++iter)
    {
        (*iter)->notificar(std::to_string(entidad), evento, tipo);
    }
}

void Model::quitarObservador(Observador* obs)
{
    this->observadores.erase(std::remove(observadores.begin(), observadores.end(), obs), observadores.end());
}

void Model::setTodosJugadoresInactivos()
{
    for(unsigned i = 0; i < CANTJUGADORESTOTALES; ++i)
    {
        this->jugadoresEnCancha[i].desactivar();
        this->notificarAObservadores(i, COMMNULL, MJU);
    }
}

void Model::definirComoLocal(char codigoCliente)
{
    if(this->cantidadLocales + 1 > 3) {
        this->definirComoVisitante(codigoCliente);
    }
    int i = this->cantidadLocales;
    bool encontreJugadorLibre = false;
    while (!encontreJugadorLibre) {
        ++i;
        encontreJugadorLibre = !this->jugadoresEnCancha[i].estaActivo();
    }
    this->clientes[codigoCliente] = i;
    this->jugadoresEnCancha[this->clientes[codigoCliente]].activar();

    this->cantidadLocales += 1;
    this->notificarAObservadores(this->cantidadLocales, DEFLOCAL, MSJ);
}

void Model::definirComoVisitante(char codigoCliente)
{
    if(this->cantidadClientes > 0 && this->cantidadVisitantes + 1 == this->cantidadClientes) {
        this->definirComoLocal(codigoCliente);
    }
    int i = this->cantidadVisitantes + 7;
    bool encontreJugadorLibre = false;
    while (!encontreJugadorLibre) {
        ++i;
        encontreJugadorLibre = !this->jugadoresEnCancha[i].estaActivo();
    }
    this->clientes[codigoCliente] = i;
    this->jugadoresEnCancha[this->clientes[codigoCliente]].activar();

    this->cantidadVisitantes += 1;

    this->notificarAObservadores(this->cantidadVisitantes, DEFVISIT, MSJ);

}

void Model::desconectarCliente(char codigoCliente)
{
    this->jugadoresEnCancha[this->clientes[codigoCliente]].desactivar();
    this->notificarAObservadores(codigoCliente,DESCJUG,ERR_CON);
}

bool Model::necesitaRenderizar() {
    if(this->renderizar) {
        this->renderizar=false;
        return true;
    }
    return this->renderizar;
}

void Model::habilitarRender() {
    this->renderizar=true;
}

void Model::setCantidadClientes(unsigned cantidad) {
    this->cantidadClientes = cantidad;
}


