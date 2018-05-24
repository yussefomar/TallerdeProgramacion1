#include "../View/InformacionIngreso.h"

#define LOGINLBR 0X0B //EQUIPOS LIBRES.
#define LOGINUNO 0X0C //EQUIPO UNO LLENO.
#define LOGINDOS 0X0D //EQUIPO DOS LLENO.
#define LOGINFUL 0X0E //EQUIPOS LLENOS.
#define LOGINERR 0X0F //ERROR CREDENCIALES.
#define LOGINESP 0X10 //INGRESO CORRECTO PERO EN ESPERA.
#define LOGINYES 0X11 //INGRESO CORRECTO E INICIA.

InformacionIngreso::InformacionIngreso(bool error)
{
    this->error = error;
    this->nombre = "";
    this->password = "";
    this->equipo = "";
    this->mensaje = "";
    this->equipoUno = true;
    this->equipoDos = true;
}

InformacionIngreso::~InformacionIngreso()
{
    //dtor
}

void InformacionIngreso::procesarRespuesta(char respuesta)
{
    if(respuesta == LOGINLBR) {
        this->error = false;
        this->equipoUno = true;
        this->equipoDos = true;
        return;
    }
    if(respuesta == LOGINUNO) {
        this->error = false;
        this->equipoUno = false;
        return;
    }
    if(respuesta == LOGINDOS) {
        this->error = false;
        this->equipoDos = false;
        return;
    }
    if(respuesta == LOGINFUL) {
        this->error = false;
        this->equipoUno = false;
        this->equipoDos = false;
        return;
    }
    if(respuesta == LOGINERR) {
        this->error = true;
        this->nombre = "";
        this->password = "";
        this->equipo = "";
        this->mensaje = "Las credenciales no coinciden.";
        return;
    }
    if(respuesta == LOGINESP) {
        this->error = false;
        this->mensaje = "Ingreso correcto, esperando inicio.";
        return;
    }
    if(respuesta == LOGINYES) {
        this->error = false;
        this->mensaje = "Empezando juego!";
        return;
    }
}
