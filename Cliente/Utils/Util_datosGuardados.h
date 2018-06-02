#ifndef UTIL_DATOSGUARDADOS_H_
#define UTIL_DATOSGUARDADO_H_

#include <iostream>
#include <string>
#include <list>


using namespace std;

struct DatosConexion
{
   DatosConexion()
    {
        ip="";
        puerto="";
        tieneDatos = 0; //1 para dato 0 para vacio
    }
    DatosConexion(std::string p_puerto, std::string p_ip)
    {
        ip= p_ip;
        puerto= p_puerto;
        tieneDatos = 1; //1 para dato 0 para vacio
    }
    std::string puerto;
    std::string ip;
    bool tieneDatos;
};


class Util_datosGuardados
{
public:

    bool fileExist(const std::string& name);
    void setDatosConexionFile(std::string p_puerto, std::string p_ip);
    DatosConexion getDatosConexion();
    void writeSingleLine(string line);
};

#endif
