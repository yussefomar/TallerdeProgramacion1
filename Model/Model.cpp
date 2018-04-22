#include "Model.h"
#include "ViewModel.h"
#define CANTJUGADORES 7


Model::Model()
{
    this->jugadores = new Jugador[CANTJUGADORES]();
    this->nroJugadorActivo = 4;
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
    try
    {
        NotifyMessage("INGRESAMOS EN EL METODO: addCommand", "MODEL");
        //hay que tirar una excepcion
        if(command == nullptr)
            return;
        this->commandsToApply.push_back(command);
        NotifyMessage("SALIMOS DEL METODO: addCommand", "MODEL");
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "MODEL");
        NotifyError(re.what(), "MODEL");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "MODEL");
        NotifyError(ex.what(), "MODEL");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "MODEL");
    }
}

void Model::cambiarJugadorActivo()
{
    try
    {
        NotifyMessage("INGRESAMOS EN EL METODO: cambiarJugadorActivo", "MODEL");

        while (!((this->jugadores[(this->nroJugadorActivo + 1) % CANTJUGADORES]).collide(this->camara )))
        {
            NotifyMessage("colision 2", "MODEL");
            (this->jugadores[(this->nroJugadorActivo)]).desactivar();
            this->nroJugadorActivo = (this->nroJugadorActivo + 1) % CANTJUGADORES;
        }
        (this->jugadores[(this->nroJugadorActivo)]).desactivar();

        NotifyMessage("DESACTIVE ACTUAL JUGADOR", "MODEL");
        this->nroJugadorActivo = (this->nroJugadorActivo + 1) % CANTJUGADORES;
        (this->jugadores[(this->nroJugadorActivo)]).activar();
        NotifyMessage("ACTIVE OTRO JUGADOR", "MODEL");

        NotifyMessage("SALIMOS DEL METODO: cambiarJugadorActivo", "MODEL");
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "MODEL");
        NotifyError(re.what(), "MODEL");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "MODEL");
        NotifyError(ex.what(), "MODEL");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "MODEL");
    }
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
    try
    {
        NotifyMessage("INGRESAMOS EN EL METODO: update", "MODEL");
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
        this->pelota.move();
        NotifyMessage("SALIMOS DEL EL METODO: update", "MODEL");
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "MODEL");
        NotifyError(re.what(), "MODEL");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "MODEL");
        NotifyError(ex.what(), "MODEL");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "MODEL");
    }
}

void Model::setCamara(SDL_Rect * camara)
{
    NotifyMessage("INGRESAMOS AL METODO: setCamara", "MODEL");
    this->camara = camara;
    NotifyMessage("SALIMOS DEL METODO: setCamara", "MODEL");
}

void Model::setFormacion(Formacion* formacion)
{
    NotifyMessage("INGRESAMOS AL METODO: setFormacion", "MODEL");
    formacion->setPosicionInicial(this->jugadores);
    NotifyMessage("SALIMOS DEL METODO: setFormacion", "MODEL");

}

void Model::setCasaca(std::string casacaName)
{
    try
    {
        NotifyMessage("INGRESAMOS AL METODO: setCasaca", "MODEL");
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
        NotifyMessage("SALIMOS DEL METODO: setCasaca", "MODEL");
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "CONTROLLER");
        NotifyError(re.what(), "CONTROLLER");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "CONTROLLER");
        NotifyError(ex.what(), "CONTROLLER");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "CONTROLLER");
    }
}
