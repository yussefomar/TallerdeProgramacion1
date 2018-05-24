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
        bool nombreIngresado;
        bool passwordIngresado;
        bool equipoIngresado;
        bool error;
        bool equipoUno;
        bool equipoDos;
        virtual void procesarRespuesta(char respuesta);
        InformacionIngreso(bool error);
        virtual ~InformacionIngreso();

    protected:

    private:
};

#endif // INFORMACIONINGRESO_H
