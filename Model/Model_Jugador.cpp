#include "Model_Jugador.h"


Jugador::Jugador()
{
    this->estado = &(this->inactivo);

    this->casaca = 1;
    this->mCollider.x = this->estado->getPosX();
    this->mCollider.y = this->estado->getPosY();
    this->mCollider.w = ANCHO_JUGADOR;
    this->mCollider.h = ALTO_JUGADOR;

}

void Jugador::setPosInitX(int posX) {
    this->estado->setPosInitX(posX);
}

void Jugador::setPosInitY(int posY) {
    this->estado->setPosInitY(posY);
}

void Jugador::move()
{
    this->estado->move();
    this->mCollider.x = this->estado->getPosX();
    this->mCollider.y = this->estado->getPosY();
}


void Jugador::patearPelota(Pelota* pelota)
{
    SDL_Rect colli_pelo;
    colli_pelo.x=pelota->getPosX();
    colli_pelo.y=pelota->getPosY();
    colli_pelo.h=pelota->ANCHO_PELOTA;
    colli_pelo.w=pelota->ANCHO_PELOTA;
    if(this->checkCollisionPelota(&colli_pelo))
    {

        pelota->move();//mueve en cualquier direccion,no tiene logica la pelota segun el tp.

    }


}

void Jugador::recuperaPelota(Pelota* pelota)
{
    SDL_Rect colli_pelo;
    colli_pelo.x=pelota->getPosX();
    colli_pelo.y=pelota->getPosY();
    colli_pelo.h=pelota->ANCHO_PELOTA;
    colli_pelo.w=pelota->ANCHO_PELOTA;


    if(this->checkCollisionPelota((&colli_pelo)))
    {
        printf("detecto pelota para mantenerla");
        // pelota->aumentarVelocidadX();
        //pelota->aumentarVelocidadY();

        //pelota->aumentarVelocidadY();
        //pelota->aumentarVelocidadX();
//pelota->setPosX(this->activo.getPosX());
//          pelota->setPosY(this->activo.getPosY());
        /*               pelota->setVelocidadX(this->activo.getVelX());
                       pelota->setVelocidadY(this->activo.getVelY());
                     pelota->move();*/
        /*
                      pelota->setPosX(this->activo.getPosX());
                      pelota->setPosY(this->activo.getPosY());
                      pelota->setVelocidadX(this->activo.getVelX());
                        pelota->setVelocidadY(this->activo.getVelY());
                        pelota->move();*/

//pelota->setVelocidadX(this->getVelX());
        //            pelota->setVelocidadY(this->getVelY());

        //ver que ejecta si es aumentavelocidax entonces aumento la pelota en x
    }

}


bool Jugador::checkCollisionPelota( SDL_Rect* pelota)
{
    //The sides of the rectangles
    int leftPelota, leftJugador;
    int rightPelota, rightJugador;
    int topPelota, topJugador;
    int bottomPelota, bottomJugador;

    //Calculate the sides of rect A
    leftPelota = pelota->x;
    rightPelota = pelota->x + pelota->w;
    topPelota = pelota->y;
    bottomPelota = pelota->y + pelota->h;

    //Calculate the sides of rect B
    leftJugador = this->mCollider.x;

    rightJugador = this->mCollider.x + this->mCollider.w;

    topJugador = this->mCollider.y;

    bottomJugador = this->mCollider.y + this->mCollider.h;



    //If any of the sides from A are outside of B
    if( bottomJugador <= topPelota )
    {
        return false;
    }

    if( topJugador>=  bottomPelota )
    {
        return false;
    }

    if( leftJugador >=  rightPelota  )
    {
        return false;
    }

    if( rightJugador <= leftPelota )
    {
        return false;
    }


    //If none of the sides from A are outside B
    return true;
}

int Jugador::getPosX()
{
    return this->estado->getPosX();
}

int Jugador::getPosY()
{
    return this->estado->getPosY();
}

void Jugador::setPosX(int PosX)
{
    this->estado->setPosX(PosX);
}

void Jugador::setPosY(int PosY)
{
    this->estado->setPosY(PosY);
}

void Jugador::setCasacaAlternativa()
{
    this->casaca = 0 ;
}


void Jugador::disminuirVelocidadX()
{
    this->estado->disminuirVelocidadX();
}

void Jugador::disminuirVelocidadY()
{
    this->estado->disminuirVelocidadY();
}

void Jugador::aumentarVelocidadX()
{
    this->estado->aumentarVelocidadX();
}

void Jugador::aumentarVelocidadY()
{
    this->estado->aumentarVelocidadY();
}

int Jugador::getVelX()
{
    return this->estado->getVelX();
}

int Jugador::getVelY()
{
    return this->estado->getVelY();
}
bool Jugador::casacaPrincipal()
{
    return this->casaca;
}

void Jugador::detenerVelocidad()
{
    this->estado->detenerVelocidad();
}
bool Jugador::estaActivo()
{
    return this->estado->estaActivo();
}
void Jugador::activar()
{
    this->activo.copiarEstado(this->estado);
    this->estado = &(this->activo);
}
void Jugador::desactivar()
{
    this->inactivo.copiarEstado(this->estado);
    this->estado = &(this->inactivo);
}
bool Jugador::collide(SDL_Rect * camara)
{
//The sides of the rectangles
    int leftCam, leftJugador;
    int rightCam, rightJugador;
    int topCam, topJugador;
    int bottomCam, bottomJugador;

    //Calculate the sides of rect A
    leftCam = camara->x;

    rightCam = camara->x + camara->w;

    topCam = camara->y;

    bottomCam = camara->y + camara->h;

    //Calculate the sides of rect B
    leftJugador = this->mCollider.x;
    printf("leftcam %i - ",leftCam);
    printf("leftJugador - %i\n",leftJugador);
    rightJugador = this->mCollider.x + this->mCollider.w;
    printf("rightCam %i",rightCam);
    printf("rightJugador %i\n",rightJugador);
    topJugador = this->mCollider.y;
    printf("topCam %i",topCam);
    printf("topJugador %i\n",topJugador);
    bottomJugador = this->mCollider.y + this->mCollider.h;
    printf("bottomCam %i",topCam);
    printf("bottomJugador %i\n\n\n",bottomJugador);


    //If any of the sides from A are outside of B

    if( bottomJugador <= topCam )
    {
        return false;
    }

    if( topJugador>= bottomCam )
    {
        return false;
    }

    if( leftJugador >= rightCam )
    {
        return false;
    }

    if( rightJugador <= leftCam )
    {
        return false;
    }

    return true;
}

void Jugador::acelerar() {
    this->estado->acelerar();
}

void Jugador::desacelerar() {
    this->estado->desacelerar();
}
