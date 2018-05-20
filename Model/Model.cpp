#include "../Model/Model.h"
#include "../View/ViewModel.h"

#define CANTJUGADORES 7


Model::Model()
{
    this->jugadores = new Jugador[CANTJUGADORES]();
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

Jugador* Model::getJugadorActivo()
{
    return &(this->jugadores[this->nroJugadorActivo]);
}

void Model::agregarCambio(Command* cambio)
{

//        NotifyMessage("Iniciamos: addCommand", "Model.cpp");
    this->cambios.push(cambio);
//        NotifyMessage("Terminamos: addCommand", "Model.cpp");

}

void Model::jugadorActivoCambia()
{

//        NotifyMessage("Iniciamos: jugadorActivoCambia", "Model.cpp");
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

//        NotifyMessage("Iniciamos: update", "Model.cpp");

    if(!this->cambios.empty())
    {
        Command* cambio = this->cambios.front();
        cambio->execute();
        this->cambios.pop();
    }


    for(int i = 0; i < CANTJUGADORES; ++i)
    {
        this->jugadores[i].move();
    }
    this->pelota.move();
//        NotifyMessage("Terminamos: update", "Model.cpp");


}

void Model::moverJuego()
{
    for(int i = 0; i < CANTJUGADORES; ++i)
    {
        this->jugadores[i].move();
    }
    this->pelota.move();
}

void Model::setCamara(SDL_Rect * camara)
{
//    NotifyMessage("Iniciamos: setCamara", "Model.cpp");
    this->camara = camara;
//    NotifyMessage("Terminamos: setCamara", "Model.cpp");
}

void Model::setFormacionLocal(Formacion* formacion)
{
//    NotifyMessage("Iniciamos: setFormacion", "Model.cpp");
    this->formacion= formacion;
    this->formacion->setPosicionInicialLocal(this->jugadores);
//    NotifyMessage("Terminamos: setFormacion", "Model.cpp");

}

void Model::setPelotaParada()
{
    this->juegoIniciado= false;
}

void Model::setPelotaEnMovimiento()
{
    this->juegoIniciado= true;
}

bool Model::pelotaEnMovimiento()
{
    return this->juegoIniciado;
}

void Model::setCasaca(std::string casacaName)
{

    // NotifyMessage("Iniciamos: setCasaca", "Model.cpp");
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
    //NotifyMessage("Terminamos: setCasaca", "Model.cpp");

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
    this->Notify(this->nroJugadorActivo, INCVELX);
}

void Model::jugadorActivoAumentaVelocidadEnY()
{
    this->jugadores[this->nroJugadorActivo].aumentarVelocidadY();
    this->Notify(this->nroJugadorActivo, INCVELY);
}

void Model::jugadorActivoDisminuyeVelocidadEnX()
{
    this->jugadores[this->nroJugadorActivo].disminuirVelocidadX();
    this->Notify(this->nroJugadorActivo, DECVELX);
}

void Model::jugadorActivoDisminuyeVelocidadEnY()
{
    this->jugadores[this->nroJugadorActivo].disminuirVelocidadY();
    this->Notify(this->nroJugadorActivo, DECVELY);
}

void Model::jugadorActivoAcelera()
{
    this->jugadores[this->nroJugadorActivo].acelerar();
    this->Notify(this->nroJugadorActivo, ACCJUG);
}

void Model::jugadorActivoDesacelera()
{
    this->jugadores[this->nroJugadorActivo].desacelerar();
    this->Notify(this->nroJugadorActivo, DESJUG);
}

void Model::jugadorActivoPateaPelota()
{
    this->jugadores[this->nroJugadorActivo].patearPelota(&(this->pelota));
    this->Notify(this->nroJugadorActivo, PATPELO);
}

void Model::jugadorActivoRecuperaPelota()
{
    this->jugadores[this->nroJugadorActivo].recuperaPelota(&(this->pelota));
    this->Notify(this->nroJugadorActivo, RECUPELO);
}

void Model::jugadorActivoDetener()
{
    this->jugadores[this->nroJugadorActivo].detenerVelocidad();
    this->Notify(this->nroJugadorActivo, STOPJUG);
}

/*Servicios del modelo en modo online*/
void Model::aumentarVelocidadEnX(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].aumentarVelocidadX();
    this->Notify(nrojugador, INCVELX);
}

void Model::aumentarVelocidadEnY(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].aumentarVelocidadY();
    this->Notify(nrojugador, INCVELY);
}

void Model:: disminuirVelocidadY(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].disminuirVelocidadY();
    this->Notify(nrojugador, DECVELY);
}

void Model:: disminuirVelocidadX(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].disminuirVelocidadX();
    this->Notify(nrojugador, DECVELX);
}

void Model:: desacelerar(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].desacelerar();
    this->Notify(nrojugador, DESJUG);
}

void Model:: patearPelota(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].patearPelota(this->getPelota());
    this->Notify(nrojugador, PATPELO);
}

void Model:: recuperaPelota(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].recuperaPelota(this->getPelota());
    this->Notify(nrojugador, RECUPELO);
}

void Model:: stopJugador(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].detenerVelocidad();
    this->Notify(nrojugador, STOPJUG);
}

void Model::acelerar(char codigojugador)
{
    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].acelerar();
    this->Notify(nrojugador, ACCJUG);

    //this->notificarAObservadores(nrojugador, ACCJUG);
}

//void Model::agregarObservador(IObserver* observador)
//{
//    this->observadores.push_back(observador);
//}
//
//void notificarAObservadores(char entidad, char evento)
//{
//    for (std::list<IObserver*>::iterator it=this->observadores.begin(); it != this->observadores.end(); ++it)
//    {
//        (*it)->notificar(entidad, evento);
//    }
//
//}


