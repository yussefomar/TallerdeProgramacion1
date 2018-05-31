#ifndef PASARPELOTA_H
#define PASARPELOTA_H

#include "CommandCtrl.h"

class PasarPelota : public CommandCtrl
{
public:
    PasarPelota(Model* model);
    virtual ~PasarPelota();
    void execute();
    char getCodigoComando();

protected:

private:
};

#endif // PASARPELOTA_H
