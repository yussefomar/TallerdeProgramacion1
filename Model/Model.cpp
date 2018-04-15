#include "Model.h"
#include "ViewModel.h"
#define CANTJUGADORES 7


Model::Model()
{
    this->jugadores = new Jugador[CANTJUGADORES]();
    this->nroJugadorActivo = 0;
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

void Model::addCommand(Command* command)
{
    //hay que tirar una excepcion
    if(command == nullptr)
        return;
    this->commandsToApply.push_back(command);
}

void Model::cambiarJugadorActivo()
{
        while (!((this->jugadores[(this->nroJugadorActivo + 1) % CANTJUGADORES]).collide(this->camara )))
        {
            printf("\n\n colision 2\n\n");
            (this->jugadores[(this->nroJugadorActivo)]).desactivar();
            this->nroJugadorActivo = (this->nroJugadorActivo + 1) % CANTJUGADORES;

        }
    (this->jugadores[(this->nroJugadorActivo)]).desactivar();
     this->nroJugadorActivo = (this->nroJugadorActivo + 1) % CANTJUGADORES;
    (this->jugadores[(this->nroJugadorActivo)]).activar();
}
//El detener jugadores ya esta implicito en el estado.
//Y si no, deberia estarlo.s
//void Model::detenerJugadores()
//{
//    for(int i = 0; i < CANTJUGADORES; ++i)
//    {
//        this->jugadores[i].stop();
//    }
//}

void Model::update()
{
    Command* command = nullptr;
    while(!this->commandsToApply.empty())
    {
        command = this->commandsToApply.front();
        command->execute();
        this->commandsToApply.pop_front();
    }
    for(int i = 0; i < CANTJUGADORES; ++i)
    {
        this->jugadores[i].move();
    }
}

void Model::setCamara(SDL_Rect * camara)
{
    this->camara = camara;
}

void Model::setFormacion(Formacion* formacion) {
    formacion->setPosicionInicial(this->jugadores);
}

