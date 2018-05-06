#include "../Controller/Controller.h"
#include "../Controller/DisminuirVelocidadY.h"
#include "../Controller/AumentarVelocidadY.h"
#include "../Controller/DisminuirVelocidadX.h"
#include "../Controller/AumentarVelocidadX.h"
#include "../Controller/CambiarJugador.h"
#include "../Controller/StopJugador.h"
#include "../Controller/Acelerar.h"
#include "../Controller/Desacelerar.h"
#include "../Controller/PatearPelota.h"
#include "../Controller/RecuperaPelota.h"

#define CANTCOMMANDS 10


enum IDCommand {DECVELX, DECVELY, INCVELX, INCVELY, CAMBJUG, STOPJUG, ACCJUG, DESJUG,PATPELO,RECUPELO};


Controller::Controller(Model* model)
{
    this->model = model;
    this->commands = std::vector<Command*>(CANTCOMMANDS);
    this->commands[DECVELX] = new DisminuirVelocidadX(model);
    this->commands[DECVELY] = new DisminuirVelocidadY(model);
    this->commands[INCVELX] = new AumentarVelocidadX(model);
    this->commands[INCVELY] = new AumentarVelocidadY(model);
    this->commands[CAMBJUG] = new CambiarJugador(model);
    this->commands[STOPJUG] = new StopJugador(model);
    this->commands[ACCJUG] = new Acelerar(model);
    this->commands[DESJUG] = new Desacelerar(model);

    this->commands[PATPELO] = new PatearPelota(model);
    this->commands[RECUPELO] = new RecuperaPelota(model);


    this->quit = false;
}

Controller::~Controller()
{
    for(unsigned i = 0; i < CANTCOMMANDS; ++i)
    {
        delete this->commands[i];
    }
}

bool Controller::quitPressed()
{
    return this->quit;
}

void Controller::processInput()
{
    try
    {
        NotifyMessage("Inicia: processInput", "Controller.cpp");
        while( SDL_PollEvent( &(this->e) ) != 0 )
        {
            if( this->e.type == SDL_QUIT )
            {
                this->quit = true;
            }
            this->model->addCommand(this->handleEvent(this->e));
        }
        //agregarComandoNUll para forzar el flujo de datos
        //tanto en el modelo offline como en el online
        NotifyMessage("Inicia: processInput", "Controller.cpp");
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Controller.cpp");
        NotifyError(re.what(), "Controller.cpp");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Controller.cpp");
        NotifyError(ex.what(), "Controller.cpp");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Controller.cpp");
    }
}

Command* Controller::handleEvent(SDL_Event& e)
{
    Command* command = nullptr;
    try
    {
        NotifyMessage("Inicia: handleEvent", "Controller.cpp");

        if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
        {
            NotifyMessage("Chequeamos: SDL_KEYDOWN", "Controller.cpp");
            switch( e.key.keysym.sym )
            {
            case SDLK_s:
                command = this->commands[RECUPELO];
                break;
            case SDLK_d:
                command = this->commands[PATPELO];
                break;
            case SDLK_UP:
                command = this->commands[DECVELY];
                break;
            case SDLK_DOWN:
                command = this->commands[INCVELY];
                break;
            case SDLK_LEFT:
                command = this->commands[DECVELX];
                break;
            case SDLK_RIGHT:
                command = this->commands[INCVELX];
                break;
            case SDLK_SPACE:
                command = this->commands[CAMBJUG];
                break;
            case SDLK_f:
                command = this->commands[ACCJUG];
            }
        }
        //If a key was released
        else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
        {

            NotifyMessage("Chequeamos: SDL_KEYUP", "Controller.cpp");
            switch( e.key.keysym.sym )
            {
            case SDLK_UP:
                if (this->model->getJugadorActivo()->getVelY()<0){
                command = this->commands[INCVELY];}
                break;
            case SDLK_DOWN:
             if (this->model->getJugadorActivo()->getVelY()>0){
                command = this->commands[DECVELY];
                }
                break;
            case SDLK_LEFT:
             if (this->model->getJugadorActivo()->getVelX()<0){
                command = this->commands[INCVELX];
                }
                break;
            case SDLK_RIGHT:
            if (this->model->getJugadorActivo()->getVelX()>0){
                command = this->commands[DECVELX];
                }
                break;
            case SDLK_f:
                command = this->commands[DESJUG];
            }
        }
        NotifyMessage("Finaliza: handleEvent", "Controller.cpp");
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Controller.cpp");
        NotifyError(re.what(), "Controller.cpp");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Controller.cpp");
        NotifyError(ex.what(), "Controller.cpp");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Controller.cpp");
    }
    return command;
}
