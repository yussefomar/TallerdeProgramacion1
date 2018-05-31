#ifndef UTIL_CONFIGURACION_H_
#define UTIL_CONFIGURACION_H_

#include "../Model/Model.h"
#include "../Model/Model_Jugador.h"
#include "../Model/Formacion312.h"
#include "../Model/Formacion33.h"
#include "../Model/Formacion321.h"
#include "../Utils/Util_Parser.h"
#include "../Utils/Util_LoggerSubject.h"

#include <iostream>
#include <string>
#include <list>

using namespace std;


class Util_Configuracion: public Util_LoggerSubject
{
public:
    Util_Configuracion(Model* model, Util_LoggerObserver* loggerObserver);
    virtual ~Util_Configuracion();
    bool inicializar(std::string pathIndicado, std::string pathDefault);
    int GenerarLevel(std::string &name); //1=Debug, 2=Info, 3=Error
    int GenerarCasaca(std::string &name); //0 principal o 1 para la suplente
    void close();

private:
    Model* model;
    Formacion312 formacion312;
    Formacion33 formacion33;
    Formacion321 formacion321;


};

#endif
