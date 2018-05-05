#ifndef MODELOCLIENTE_H
#define MODELOCLIENTE_H

#include <Model.h>


class ModeloCliente : public Model
{
public:
    ModeloCliente(Model* model);
    virtual ~ModeloCliente();

//    /*Datos del Modelo*/
//    virtual Pelota* getPelota();
//    virtual Jugador* getJugadorNro(int i);
//    virtual Jugador* getJugadorActivo();
//    virtual std::string  getCasaca();
//    virtual void setCamara(SDL_Rect * camara);
//    virtual void setFormacion(Formacion* formacion);
//    virtual void setCasaca(std::string casacaName);
//
//    /*Servicios del Modelo*/
//    virtual void addCommand(Command* command);
//    virtual void aumentarVelocidadJugadorActivoEnX();
//    virtual void aumentarVelocidadJugadorActivoEnY();
//    virtual void disminuirVelocidadJugadorActivoEnX();
//    virtual void disminuirVelocidadJugadorActivoEnY();
//    virtual void cambiarJugadorActivo();
//    virtual void update();

protected:

private:
    Model* model;
};

#endif // MODELOCLIENTE_H
