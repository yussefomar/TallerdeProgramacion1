#ifndef UTIL_PERSITENCIA_H_
#define UTIL_PERSITENCIA_H_

#include "../Model/Model.h"
#include "../Model/Model_Jugador.h"
#include "../Model/Formacion312.h"
#include "../Model/Formacion33.h"
#include "../Model/Formacion321.h"
#include "../Utils/Util_Configuracion.h"
#include "../Utils/Util_LoggerSubject.h"

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Util_Persistencia: public Util_LoggerSubject
{
public:
    Util_Persistencia(Model* model, Util_LoggerObserver* loggerObserver);
    virtual ~Util_Persistencia();
    bool inicializar();
    void close();

private:
    Model* model;





};

#endif
