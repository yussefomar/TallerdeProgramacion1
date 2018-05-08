#ifndef AUMENTARVELOCIDADYNET_H
#define AUMENTARVELOCIDADYNET_H

#include <CommandNet.h>
#include "../Model/Model.h"

class AumentarVelocidadYNet : public CommandNet
{
    public:
        AumentarVelocidadYNet(Model* model);
        virtual ~AumentarVelocidadYNet();
        void  execute();


char getCodigoComando() ;




    protected:

    private:
        Model* model;
};

#endif // AUMENTARVELOCIDADYNET_H
