#ifndef MODEL_JUGADOR_H_
#define MODEL_JUGADOR_H_

#include <SDL2/SDL.h>

#include "../Model/LTexture.h"
#include "../Model/Estado.h"
#include "../Model/Activo.h"
#include "../Model/Inactivo.h"
#include "../Model/Model_Pelota.h"

class Jugador
{
public:
    //The dimensions of the dot
    static const int ANCHO_JUGADOR = 62;
    static const int ALTO_JUGADOR = 62;
    //Maximum axis velocity of the dot
    static const int VELOCIDAD_JUGADOR = 3;

    //Initializes the variables
    Jugador();

    //Moves the dot
    void move();

    //Position accessors
    int getPosX();
    int getPosY();
    //Position accessors
    int getVelX();
    int getVelY();
    bool recuperaPelota(Pelota* pelota);
    bool recibirPelota(Pelota* pelota);
    void patearPelota(Pelota* pelota );
    void pasaPelota(Pelota* pelota, Jugador * jugador );
    void setPosX(int PosX);
    void setPosY(int PosY);

    void setPosInitX(int posX);
    void setPosInitY(int posY);


    void disminuirVelocidadX();
    void disminuirVelocidadY();
    void aumentarVelocidadX();
    void aumentarVelocidadY();
    bool estaActivo();
    void detenerVelocidad();

    void activar();
    void desactivar();

    void setCasacaAlternativa();

    void setDireccion(double direccion);
    bool casacaPrincipal();
    bool collide(SDL_Rect * camara);
    void acelerar();
    void desacelerar();
    double getDireccion();
    bool checkCollisionPelota(SDL_Rect *pelota);
    void updateDirection();
    int getAceleracion();
    void poseePelota();
    void noPoseePelota();
    bool getPosesion();
    bool getAcelero();
    void terminoDePatearPelota();
    bool patearPelota();
    void setPosesion(bool tienePelota);
    void updateAceleracion(int ac);
    void updateVelocidad ( int velx, int vely);
    std::string datosString();

private:
    SDL_Rect mCollider;
    int casaca;
    Estado* estado;
    Activo activo;
    Inactivo inactivo;
    double direccion;
    bool conPelota;
    Pelota * pelota;
    bool pateoPelota;
};

#endif
