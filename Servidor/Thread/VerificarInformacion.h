#ifndef VERIFICARINFORMACION_H
#define VERIFICARINFORMACION_H

#include <Thread.h>
#include "Cliente.h"
#include "ModeloServidor.h"

class VerificarInformacion : public Thread
{
    public:
        VerificarInformacion(Cliente* cliente, ModeloServidor* modeloServidor);
        virtual ~VerificarInformacion();
        void procesoAEjecutar();

    protected:

    private:
        Cliente* cliente;
        ModeloServidor* modelo;
};

#endif // VERIFICARINFORMACION_H
