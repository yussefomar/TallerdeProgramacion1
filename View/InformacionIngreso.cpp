#include "../View/InformacionIngreso.h"

InformacionIngreso::InformacionIngreso(bool error)
{
    this->error = error;
    this->nombre = "";
    this->password = "";
    this->equipo = "";
    this->mensaje = "";
}

InformacionIngreso::~InformacionIngreso()
{
    //dtor
}
