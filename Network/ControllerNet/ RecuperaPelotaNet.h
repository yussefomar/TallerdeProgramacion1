#ifndef RECUPERAPELOTANET_H
#define RECUPERAPELOTANET_H

#include <CommandNet.h>
#include "../Model/Model.h"

class RecuperaPelotaNet : public CommandNet
{
    public:
         RecuperaPelotaNet(Model* model);
        virtual ~ RecuperaPelotaNet();

    protected:

    private:
        Model* model;
};

#endif //  RECUPERAPELOTANET_H
