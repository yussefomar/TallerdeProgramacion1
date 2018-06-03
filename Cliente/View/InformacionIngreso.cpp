#include "../View/InformacionIngreso.h"

#define LI_NOMBRE_OK 0X0B //NOMBRE CORRECTO.
#define LI_NOMBRE_ERROR 0X0C //NOMBRE INCORRECTO.
#define LI_NOMBRE_REPETIDO 0X0D //NOMBRE EXISTENTE.
#define LI_CREDENCIALES_OK 0X0E //CREDENCIALES CORRECTAS.
#define LI_CREDENCIALES_ERROR 0X0F //CREDENCIALES INCORRECTAS.

InformacionIngreso::InformacionIngreso(bool error)
{
    this->error = error;
    this->nombre = "";
    this->password = "";
    this->equipo = "";
    this->ip = "";
    this->puerto = "";
    this->mensaje = "";
    this->espera = false;
    this->arranca = false;
    this->equipoUno = true;
    this->equipoDos = true;
    this->nombreIngresado = false;
    this->passwordIngresado = false;
    this->equipoIngresado = false;
    this->ipIngresado = false;
    this->puertoIngresado = false;
}

InformacionIngreso::~InformacionIngreso()
{
    //dtor
}

void InformacionIngreso::procesarRespuesta(char respuesta)
{
    //NOMBRE CORRECTO.
    if(respuesta == LI_NOMBRE_OK)
    {
        this->nombreIngresado = true;
        this->mensaje = "Nombre ingresado correctamente.";
        return;
    }
    //NOMBRE INCORRECTO.
    if(respuesta == LI_NOMBRE_ERROR)
    {
        this->nombreIngresado = false;
        this->mensaje = "Ese nombre no fue configurado, pruebe otro.";
        this->nombre = "";
        return;
    }
    //NOMBRE EXISTENTE.
    if(respuesta == LI_NOMBRE_REPETIDO)
    {
        this->nombreIngresado = false;
        this->mensaje = "Ese nombre ya pertenece a otro jugador, pruebe otro.";
        this->nombre = "";
        return;
    }
    //CREDENCIALES CORRECTAS.
    if(respuesta == LI_CREDENCIALES_OK)
    {
        this->nombreIngresado = true;
        this->passwordIngresado = true;
        this->mensaje = "Credenciales Correctas.";
        return;
    }
    //CREDENCIALES INCORRECTAS.
    if(respuesta == LI_CREDENCIALES_ERROR)
    {
        this->nombreIngresado = false;
        this->passwordIngresado = false;
        this->equipoIngresado = false;
        this->nombre = "";
        this->equipo = "";
        this->password = "";
        this->mensaje = "Credenciales Incorrectas.";
        return;
    }
}

void InformacionIngreso::procesarConectividad(bool respuesta)
{
    if(!respuesta)
    {
        this->ipIngresado = false;
        this->puertoIngresado = false;
        this->nombreIngresado = false;
        this->ip = "";
        this->puerto = "";
        this->nombre = "";
        this->mensaje = "Error al conectar con ese IP y PUERTO.";
    }
    else
    {
        this->ipIngresado = true;
        this->puertoIngresado = true;
        this->mensaje = "Conectado con ese IP y PUERTO.";
    }
}

void InformacionIngreso::equipoErroneo()
{
    this->equipoIngresado = false;
    this->equipo = "";
    this->mensaje = "No ha elegido un equipo valido";
}
