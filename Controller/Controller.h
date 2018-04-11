#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"
#include "Command.h"
#include <SDL2/SDL.h>

#include "DesminuirVelocidadY.h"
#include "AumentarVelocidadY.h"
#include "DisminuirVelocidadX.h"
#include "AumentarVelocidadX.h"



class Controller
{
    public:
        Controller();
        virtual ~Controller();
        void setModel(Model& model);
        void processInput();
        bool quitPressed();

    protected:

    private:
        Model model;
        bool quit;
        SDL_Event event;

        DesminuirVelocidadY desminuirVelocidadY;
        AumentarVelocidadY aumentarVelocidadY;
        DisminuirVelocidadX disminuirVelocidadX;
        AumentarVelocidadX aumentarVelocidadX;

        Command* handleEvent();
};

#endif // CONTROLLER_H
