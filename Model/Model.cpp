#include "Model.h"

Model::Model()
{
    //ctor
}

Model::~Model()
{
    //dtor
}

void Model::addObserver(Observer* observer) {
    this->observers.push_front(observer);
}

void Model::addRequest(Command* command) {
    this->commands.push_back(command);
}

void Model::update() {
    Command* command;
    while(!this->commands.empty()) {
        command = this->commands.front();
        this->commands.pop_front();
        command->execute();
    }
}

Jugador* Model::getActivePlayer() {
    return &(this->jugador);
}
