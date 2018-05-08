#ifndef DISMINUIRVELOCIDADYNET_H
#define DISMINUIRVELOCIDADYNET_H

#include <CommandNet.h>
#include "../Model/Model.h"


class DisminuirVelocidadYNet : public CommandNet
{
    public:
        DisminuirVelocidadYNet(Model* model);
        virtual ~DisminuirVelocidadYNet();

        void  execute();


char getCodigoComando();


    protected:

    private:
        Model* model;
};

#endif // DISMINUIRVELOCIDADYNET_H
