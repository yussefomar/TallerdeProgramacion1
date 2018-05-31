#ifndef INFORMACIONINGRESO_H
#define INFORMACIONINGRESO_H

#include <string>

class InformacionIngreso
{
public:
    std::string nombre;
    std::string password;
    std::string equipo;
    std::string mensaje;
    std::string ip;
    std::string puerto;
    bool nombreIngresado;
    bool passwordIngresado;
    bool equipoIngresado;
    bool ipIngresado;
    bool puertoIngresado;
    bool equipoUno;
    bool equipoDos;
    bool error;
    bool lleno;
    bool espera;
    bool arranca;
    virtual void procesarRespuesta(char respuesta);
    virtual void procesarConectividad(bool respuesta);
    virtual void equipoErroneo();
    InformacionIngreso(bool error);
    virtual ~InformacionIngreso();

protected:

private:
};

#endif // INFORMACIONINGRESO_H
