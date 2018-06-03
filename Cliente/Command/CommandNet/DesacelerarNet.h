#ifndef DESACELERARNET_H
#define DESACELERARNET_H

#include "../CommandNet.h"
#include "../Model/Model.h"

class DesacelerarNet : public CommandNet
{
public:
    DesacelerarNet(Model* model);
    virtual ~DesacelerarNet();
    void  execute();
    char  getCodigoComando();
    CommandNet* getCopia();

protected:

private:
};

#endif // DESACELERARNET_H
