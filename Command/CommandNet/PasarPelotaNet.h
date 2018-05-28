#ifndef PASARPELOTANET_H
#define PASARPELOTANET_H

#include "CommandCtrl.h"

class PasarPelotaNet : public CommandCtrl
{
public:
    PasarPelotaNet(Model* model);
    virtual ~PasarPelotaNet();
    void execute();
    char getCodigoComando();

protected:

private:
};

#endif // PASARPELOTANET_H
