#ifndef STOPJUGADORNET_H
#define STOPJUGADORNET_H

#include <CommandNet.h>
#include "../Model/Model.h"

class StopJugadorNet : public CommandNet
{
    public:
        StopJugadorNet(Model* model);
        virtual ~StopJugadorNet();
        void  execute() ;

char  getCodigoComando() ;



    protected:

    private:
        Model* model;
};

#endif // STOPJUGADORNET_H
