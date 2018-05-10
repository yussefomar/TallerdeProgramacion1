#ifndef MODELOCLIENTE_H
#define MODELOCLIENTE_H
#include <Model.h>

#include "CommandNet.h"
class ModeloCliente : public Model
{
public:
    ModeloCliente(Model* model);
    virtual ~ModeloCliente();

    /*Datos del Modelo*/
    virtual Pelota* getPelota();
    virtual Jugador* getJugadorNro(int i);
    virtual Jugador* getJugadorActivo();
    virtual std::string  getCasaca();
    virtual void setCamara(SDL_Rect * camara);
    virtual void setFormacion(Formacion* formacion);
    virtual void setCasaca(std::string casacaName);

    /*Servicios del Modelo*/
    virtual void addCommand(Command* command);
    virtual void jugadorActivoAumentaVelocidadEnX();
    virtual void jugadorActivoAumentaVelocidadEnY();
    virtual void jugadorActivoDisminuyeVelocidadEnX();
    virtual void jugadorActivoDisminuyeVelocidadEnY();
    virtual void jugadorActivoAcelera();
    virtual void jugadorActivoDesacelera();
    virtual void jugadorActivoPateaPelota();
    virtual void jugadorActivoRecuperaPelota();
    virtual void jugadorActivoDetener();
    virtual void cambiarJugadorActivo();
    virtual void update();

protected:

private:
    Model* model;
    std::vector<CommandNet*> commands;
};

#endif // MODELOCLIENTE_H
