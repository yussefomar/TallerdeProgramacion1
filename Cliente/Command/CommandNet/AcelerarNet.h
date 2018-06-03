#ifndef ACELERARNET_H
#define ACELERARNET_H

#include "../CommandNet.h"
#include "../Model/Model.h"

class AcelerarNet : public CommandNet
{
public:
    AcelerarNet(Model* model);
    virtual ~AcelerarNet();
    void  execute() ;
    char  getCodigoComando() ;
    CommandNet* getCopia();


protected:

private:
};

#endif // ACELERARNET_H
