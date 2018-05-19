#include "../Model/Model.h"
#include "../View/ViewModel.h"

#define CANTJUGADORES 7


Model::Model()
{
    this->jugadores = new Jugador[CANTJUGADORES]();
    this->nroJugadorActivo = 6;
    this->getJugadorActivo()->activar();
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

        while (!((this->jugadores[(this->nroJugadorActivo + 1) % CANTJUGADORES]).collide(this->camara )))
        {
//            NotifyMessage("Colision 2", "Model.cpp");
            (this->jugadores[(this->nroJugadorActivo)]).desactivar();
            this->nroJugadorActivo = (this->nroJugadorActivo + 1) % CANTJUGADORES;
        }
        (this->jugadores[(this->nroJugadorActivo)]).desactivar();

//        NotifyMessage("Desactive el jugador actual", "Model.cpp");
        this->nroJugadorActivo = (this->nroJugadorActivo + 1) % CANTJUGADORES;
        (this->jugadores[(this->nroJugadorActivo)]).activar();
//        NotifyMessage("Active otro jugador", "Model.cpp");

//        NotifyMessage("Terminamos: jugadorActivoCambia", "Model.cpp");

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

void Model::setFormacion(Formacion* formacion,bool local)
{
//    NotifyMessage("Iniciamos: setFormacion", "Model.cpp");
    formacion->setPosicionInicial(this->jugadores,local);
//    NotifyMessage("Terminamos: setFormacion", "Model.cpp");

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
}

void Model::jugadorActivoAumentaVelocidadEnY()
{
    this->jugadores[this->nroJugadorActivo].aumentarVelocidadY();
}

void Model::jugadorActivoDisminuyeVelocidadEnX()
{
    this->jugadores[this->nroJugadorActivo].disminuirVelocidadX();
}

void Model::jugadorActivoDisminuyeVelocidadEnY()
{
    this->jugadores[this->nroJugadorActivo].disminuirVelocidadY();
}

void Model::jugadorActivoAcelera()
{
    this->jugadores[this->nroJugadorActivo].acelerar();
}

void Model::jugadorActivoDesacelera()
{
    this->jugadores[this->nroJugadorActivo].desacelerar();
}

void Model::jugadorActivoPateaPelota()
{
    this->jugadores[this->nroJugadorActivo].patearPelota(&(this->pelota));
}

void Model::jugadorActivoRecuperaPelota()
{
    this->jugadores[this->nroJugadorActivo].recuperaPelota(&(this->pelota));
}

void Model::jugadorActivoDetener()
{
    this->jugadores[this->nroJugadorActivo].detenerVelocidad();
}

/*Servicios del modelo en modo online*/
void Model::aumentarVelocidadEnX(char codigojugador)
{

    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].aumentarVelocidadX();


}

void Model::aumentarVelocidadEnY(char codigojugador)
{

    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].aumentarVelocidadY();


}

void Model:: disminuirVelocidadY(char codigojugador)
{

    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].disminuirVelocidadY();


}

void Model:: disminuirVelocidadX(char codigojugador)
{

    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].disminuirVelocidadX();


}

void Model:: desacelerar(char codigojugador)
{

    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].desacelerar();


}

void Model:: patearPelota(char codigojugador)
{

    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].patearPelota(this->getPelota());


}

void Model:: recuperaPelota(char codigojugador)
{

    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].recuperaPelota(this->getPelota());


}

void Model:: stopJugador(char codigojugador)
{

    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].detenerVelocidad();


}

void Model::acelerar(char codigojugador)
{

    unsigned nrojugador=codigojugador;
    this->jugadores[nrojugador].acelerar();


}


