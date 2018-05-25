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
    this->espera = false;
    this->arranca = false;
    this->equipoUno = true;
    this->equipoDos = true;
    this->nombreIngresado = false;
    this->passwordIngresado = false;
    this->equipoIngresado = false;
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
        this->mensaje = "";
        return;
    }
    if(respuesta == LOGINUNO) {
        this->error = false;
        this->lleno = false;
        this->equipoUno = false;
        this->equipo = "2";
        this->equipoIngresado = true;
        this->mensaje = "Solo es posible escoger el equipo 2:";
        return;
    }
    if(respuesta == LOGINDOS) {
        this->error = false;
        this->lleno = false;
        this->equipoDos = false;
        this->equipo = "1";
        this->equipoIngresado = true;
        this->mensaje = "Solo es posible escoger el equipo 1:";
        return;
    }
    if(respuesta == LOGINFUL) {
        this->lleno = true;
        this->error = false;
        this->equipoUno = false;
        this->equipoDos = false;
        if(this->espera != true && this->arranca != true)
        {
            this->nombreIngresado = true;
            this->passwordIngresado = true;
            this->equipoIngresado = true;
            this->mensaje = "No es posible ingresar, los equipos están llenos, puede esperar.";
        }
        return;
    }
    if(respuesta == LOGINERR) {
        this->error = true;
        this->espera = false;
        this->arranca = false;
        this->nombre = "";
        this->password = "";
        this->equipo = "";
        this->mensaje = "Las credenciales no coinciden.";
        return;
    }
    if(respuesta == LOGINESP) {
        this->error = false;
        this->espera = true;
        this->arranca = false;
        this->mensaje = "Ingreso correcto, esperando inicio.";
        return;
    }
    if(respuesta == LOGINYES) {
        this->error = false;
        this->espera = false;
        this->arranca = true;
        this->mensaje = "Empezando juego!";
        return;
    }
}
