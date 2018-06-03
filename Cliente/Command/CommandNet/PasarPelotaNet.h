#ifndef PASARPELOTANET_H
#define PASARPELOTANET_H

#include "../CommandNet.h"
#include "../Model/Model.h"

class PasarPelotaNet : public CommandNet
{
public:
    PasarPelotaNet(Model* model);
    virtual ~PasarPelotaNet();
    void execute();
    char getCodigoComando();
    CommandNet* getCopia();

protected:

private:
};

#endif // PASARPELOTANET_H
