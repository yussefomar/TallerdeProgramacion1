#include <yaml-cpp/yaml.h>
#include <yaml-cpp/exceptions.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include "../Utils/Util_Persistencia.h"



Util_Persistencia::Util_Persistencia(Model* model, Util_LoggerObserver* loggerObserver)
{
    Util_Configuracion configuracion(model, loggerObserver);
    configuracion.Attach(loggerObserver); //es necesario hacer esto?

}

void Util_Persistencia::close()
{

}

Util_Persistencia::~Util_Persistencia()
{

    this->close();
}


bool Util_Persistencia::inicializar()
{
//llamo aca al inicializar de configuracion??????
    return true;
}

