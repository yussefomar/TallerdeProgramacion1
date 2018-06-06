#ifndef ESTADO_H
#define ESTADO_H

#define VELOCIDAD_NORMAL 3
#define VELOCIDAD_ACELERACION 2

class Estado
{
public:
    Estado();
    virtual ~Estado();
    //Position accessors
    int getPosX();
    int getPosY();
    //Position accessors
    int getVelX();
    int getVelY();

    void setPosX(int PosX);
    void setPosY(int PosY);

    void setPosInitX(int posX);
    void setPosInitY(int posY);
    void copiarEstado(Estado* estado);
    void disminuirVelocidadX();
    void disminuirVelocidadY();
    void aumentarVelocidadX();
    void aumentarVelocidadY();
    void detenerVelocidad();

    virtual void move() = 0;

    virtual bool estaActivo() = 0;

    virtual void acelerar() = 0;
    int getAceleracion();
    void desacelerar();
    bool getAcelero();
    //virtual void stop() = 0;
      void setVelocidadX(int velx);
    void setVelocidadY(int vely);
void setAceleracion (int ac);

protected:
    //The X and Y offsets of the dot
    int mPosX, mPosY;
    int posInitX, posInitY;
    //The velocity of the dot
    int mVelX, mVelY;
    int aceleracion;
    bool acelero;

private:
};

#endif // ESTADO_H
