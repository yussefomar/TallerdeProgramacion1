#ifndef LOGIN_H
#define LOGIN_H

#include "ModeloCliente.h"
#include "../Utils/Util_datosGuardados.h"

class LogIn
{
    public:
        LogIn(ModeloCliente* modelCliente);
        virtual ~LogIn();
        bool puedeArrancar;
    protected:

    private:
};

#endif // LOGIN_H
