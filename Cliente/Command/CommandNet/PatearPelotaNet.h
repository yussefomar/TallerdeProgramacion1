#ifndef PATEARPELOTANET_H
#define PATEARPELOTANET_H

#include "../CommandNet.h"
#include "../Model/Model.h"

class PatearPelotaNet : public CommandNet
{
public:
    PatearPelotaNet(Model* model);
    virtual ~PatearPelotaNet();
    void  execute();
    char  getCodigoComando();
    CommandNet* getCopia();

protected:

private:
};

#endif // PATEARPELOTANET_H
