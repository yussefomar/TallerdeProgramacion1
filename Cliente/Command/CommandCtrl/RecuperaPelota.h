#ifndef RECUPERAPELOTA_H
#define RECUPERAPELOTA_H

#include "CommandCtrl.h"

class RecuperaPelota  : public CommandCtrl
{
public:
    RecuperaPelota(Model* model);
    char getCodigoComando();
    virtual ~RecuperaPelota();
    void execute();

protected:

private:
};

#endif // RECUPERAPELOTA_H
