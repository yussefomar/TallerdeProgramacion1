#ifndef RECUPERARPELOTANET_H
#define RECUPERARPELOTANET_H

#include "../CommandNet.h"
#include "../Model/Model.h"

class RecuperarPelotaNet : public CommandNet
{
public:
    RecuperarPelotaNet(Model* model);
    virtual ~RecuperarPelotaNet();
    void execute() ;
    char  getCodigoComando() ;
    CommandNet* getCopia();

protected:

private:
};

#endif // RECUPERARPELOTANET_H
