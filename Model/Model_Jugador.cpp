#include "../Model/Model_Jugador.h"
#define MARGENDESELECCION 100

Jugador::Jugador()
{
    this->estado = &(this->inactivo);

    this->casaca = 1;
    this->mCollider.x = this->estado->getPosX();
    this->mCollider.y = this->estado->getPosY();
    this->mCollider.w = ANCHO_JUGADOR;
    this->mCollider.h = ALTO_JUGADOR;
    this->direccion=90.0;
    this->conPelota=false;
    this->pateoPelota=false;
}

void Jugador::setPosInitX(int posX)
{
    this->estado->setPosInitX(posX);
}

void Jugador::setPosInitY(int posY)
{
    this->estado->setPosInitY(posY);
}

void Jugador::setDireccion(double direccion)
{
    this->direccion=direccion;
}


void Jugador::move()
{
    this->estado->move();
    updateDirection();
    this->mCollider.x = this->estado->getPosX();
    this->mCollider.y = this->estado->getPosY();
    if (this->getPosesion())
    {
        // pelota->setVelocidadX(this->getVelX()*this->getAceleracion());
        // pelota->setVelocidadY(this->getVelY()*this->getAceleracion());
        pelota->setPosX(this->estado->getPosX()+ANCHO_JUGADOR/2);
        pelota->setPosY(this->estado->getPosY()+ALTO_JUGADOR/2);
        if (((this->direccion) >0)  && ((this->direccion)<180))
        {
            pelota->setPosX(pelota->getPosX()+10);
        }

        if (((this->direccion) >180)  && ((this->direccion)<360))
        {
            pelota->setPosX(pelota->getPosX()-10);
        }

        if ((((this->direccion) >=0)  && ((this->direccion)<90)) ||  ((((this->direccion) <=360)  && ((this->direccion)>270))) )
        {

            pelota->setPosY(pelota->getPosY()-10);
        }
        if (((this->direccion) >90)  && ((this->direccion)<270))
        {

            pelota->setPosY(pelota->getPosY()+10);

        }

    }

}


bool Jugador::getAcelero()
{
    return this->estado->getAcelero();

}


void Jugador::patearPelota(Pelota* pelota)
{
///va a cambiar por posee pelota
//   if(this->checkCollisionPelota((pelota->getCollider())))
    if(/*this->getPosesion() &&*/ (this->checkCollisionPelota((pelota->getCollider()))))
    {
        if (((this->direccion) >0)  && ((this->direccion)<180))
        {

            pelota->setVelocidadX(20);
        }

        if (((this->direccion) >180)  && ((this->direccion)<360))
        {

            pelota->setVelocidadX(-20);
        }

        if ((((this->direccion) >=0)  && ((this->direccion)<90)) ||  ((((this->direccion) <=360)  && ((this->direccion)>270))) )
        {

            pelota->setVelocidadY(-20);
        }
        if (((this->direccion) >90)  && ((this->direccion)<270))
        {

            pelota->setVelocidadY(20);

        }

        this->pateoPelota=true;
    }
    else
    {

        this->pateoPelota=false;
    }
    this->noPoseePelota();

}

void Jugador::terminoDePatearPelota()
{

    this->pateoPelota=false;
}

bool Jugador::patearPelota()
{
///va a cambiar por posee pelota
//   if(this->checkCollisionPelota((pelota->getCollider())))

    return this->pateoPelota;

}

void Jugador::recuperaPelota(Pelota* pelota)
{

    if(this->checkCollisionPelota((pelota->getCollider())))
    {

        this->poseePelota();
        this->pelota=pelota;
    }

}

bool Jugador::checkCollisionPelota( SDL_Rect* pelota)
{

    int leftPelota, leftJugador;
    int rightPelota, rightJugador;
    int topPelota, topJugador;
    int bottomPelota, bottomJugador;

    leftPelota = pelota->x;
    rightPelota = pelota->x + pelota->w;
    topPelota = pelota->y;
    bottomPelota = pelota->y + pelota->h;

    leftJugador = this->mCollider.x;

    rightJugador = this->mCollider.x + this->mCollider.w;

    topJugador = this->mCollider.y;

    bottomJugador = this->mCollider.y + this->mCollider.h;

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
    this->detenerVelocidad();
}
void Jugador::desactivar()
{
    this->inactivo.copiarEstado(this->estado);
    this->estado = &(this->inactivo);
}
bool Jugador::collide(SDL_Rect * camara)
{

    int leftCam, leftJugador;
    int rightCam, rightJugador;
    int topCam, topJugador;
    int bottomCam, bottomJugador;

    leftCam = camara->x +MARGENDESELECCION;

    rightCam = camara->x + camara->w -MARGENDESELECCION;

    topCam = camara->y +MARGENDESELECCION;

    bottomCam = camara->y + camara->h -MARGENDESELECCION;

    leftJugador = this->mCollider.x;
    rightJugador = this->mCollider.x + this->mCollider.w;
    topJugador = this->mCollider.y;
    bottomJugador = this->mCollider.y + this->mCollider.h;

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

void Jugador::acelerar()
{
    this->estado->acelerar();
}

void Jugador::desacelerar()
{
    this->estado->desacelerar();
}
double Jugador::getDireccion()
{
    return this->direccion;
}

int Jugador::getAceleracion()
{
    return this->estado->getAceleracion();
}

void Jugador::poseePelota()
{
    this->conPelota=true;
}
void Jugador::noPoseePelota()
{
    this->conPelota=false;
}

bool Jugador::getPosesion()
{
    return this->conPelota;
}


void Jugador::updateDirection()
{

    if (this->estado->getVelX()>0)
    {
        direccion = 90;
        if (this->estado->getVelY()>0)
        {
            direccion += 45;
        }
        if (this->estado->getVelY()<0)
        {
            direccion -= 45;
        }
    }

    if (this->estado->getVelX()<0)
    {
        direccion = 270;
        if (this->estado->getVelY()<0)
        {
            direccion += 45;
        }
        if (this->estado->getVelY()>0)
        {
            direccion -= 45;
        }
    }


    if ((this->estado->getVelX()==0 )&& (this->estado->getVelY()!=0))
    {
        direccion = 90;
        if (this->estado->getVelY()<0)
        {
            direccion -= 90;
        }
        if (this->estado->getVelY()>0)
        {
            direccion += 90;
        }
    }


}
