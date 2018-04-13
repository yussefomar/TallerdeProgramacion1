#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "Model.h"
#include "Command.h"
#include <vector>


class Controller
{
    public:
        Controller(Model* model);
        virtual ~Controller();
        Command* handleEvent(SDL_Event& e);

    protected:

    private:
        Model* model;
        std::vector<Command*> commands;
};

#endif // CONTROLLER_H
