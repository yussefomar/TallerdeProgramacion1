#ifndef UTIL_CONFIGURACION_H_
#define UTIL_CONFIGURACION_H_

#include "../ModelServidor/ModeloServidor.h"
#include "../Utils/Util_ParserUsuario.h"
// #include "../Utils/Util_LoggerSubject.h"

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Util_Configuracion
{
public:
    Util_Configuracion(ModeloServidor* model);
    virtual ~Util_Configuracion();
    void close();

private:
    ModeloServidor* modeloServidor;
};

#endif
