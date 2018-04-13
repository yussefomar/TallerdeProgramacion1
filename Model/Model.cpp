#include "Model.h"

#define CANTJUGADORES 7


Model::Model()
{
    this->jugadores = new Jugador[CANTJUGADORES]();
    this->nroJugadorActivo = 0;
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
    this->nroJugadorActivo = (this->nroJugadorActivo + 1) % CANTJUGADORES;
}

void Model::detenerJugadores()
{
    for(int i = 0; i < CANTJUGADORES; ++i)
    {
        this->jugadores[i].stop();
    }
}

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
