#ifndef DISMINUIRVELOCIDADXNET_H
#define DISMINUIRVELOCIDADXNET_H

#include "../CommandNet.h"
#include "../Model/Model.h"

class DisminuirVelocidadXNet : public CommandNet
{
public:
    DisminuirVelocidadXNet(Model* model);
    virtual ~DisminuirVelocidadXNet();
    void  execute();
    char  getCodigoComando() ;
    CommandNet* getCopia();

protected:

private:
};

#endif // DISMINUIRVELOCIDADXNET_H
