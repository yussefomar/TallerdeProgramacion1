#ifndef MODEL_H
#define MODEL_H

#include "Observer.h"
#include "Command.h"
#include "Model_Jugador.h"

#include <list>

class Model
{
    public:
        Model();
        virtual ~Model();
        void addObserver(Observer* observer);
        void update();
        void addRequest(Command* command);
        Jugador* getActivePlayer();

    protected:

    private:
        std::list<Observer*> observers;
        std::list<Command*> commands;
        //Por ahora para probar, solo hay un jugador.
        Jugador jugador;
};

#endif // MODEL_H
