#ifndef PATEARPELOTA_H
#define PATEARPELOTA_H

#include "CommandCtrl.h"

class PatearPelota : public CommandCtrl
{
public:
    PatearPelota(Model* model);
    virtual ~PatearPelota();
    void execute();
    char getCodigoComando();

protected:

private:
};

#endif // PATEARPELOTA_H
