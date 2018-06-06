#ifndef MODEL_PELOTA_H_
#define MODEL_PELOTA_H_

#include <SDL2/SDL.h>

#include "../Model/LTexture.h"

class Pelota
{
public:
    //The dimensions of the dot
    static const int ANCHO_PELOTA = 12;
    static const int ALTO_PELOTA = 12;

    //Maximum axis velocity of the dot
    static const int VELOCIDAD_PELOTA = 3;

    //Initializes the variables
    Pelota();

    //Moves the dot
    void move();

    //Position accessors
    int getPosX();
    int getPosY();
    //Position accessors
    int getVelX();
    int getVelY();

    void setPosX(int PosX);

    void setPosY(int PosY);

    void disminuirVelocidadX();

    void disminuirVelocidadY();

    void aumentarVelocidadX();
    void setLibre();
    void setEnUso();
    bool estaLibre();
    void aumentarVelocidadY();
    void setVelocidadX(int velocidad);
    void setVelocidadY(int velocidad);
    SDL_Rect * getCollider();
    std::string datosString();

private:
    //The X and Y offsets of the dot
    int mPosX, mPosY;
    bool libre;

    //The velocity of the dot
    int mVelX, mVelY;
    SDL_Rect colli_pelo;
};

#endif
