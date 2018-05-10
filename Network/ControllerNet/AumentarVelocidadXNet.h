#ifndef AUMENTARVELOCIDADXNET_H
#define AUMENTARVELOCIDADXNET_H

#include <CommandNet.h>
#include "../Model/Model.h"

class AumentarVelocidadXNet : public CommandNet
{
public:
    AumentarVelocidadXNet(Model* model);
    virtual ~AumentarVelocidadXNet();
    void  execute();
    char  getCodigoComando();

protected:

private:
};

#endif // AUMENTARVELOCIDADXNET_H
