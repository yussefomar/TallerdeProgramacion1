#ifndef RECUPERAPELOTA_H
#define RECUPERAPELOTA_H

#include "../Controller/Command.h"
#include "../Model/Model.h"

class RecuperaPelota  : public Command
{
public:
    RecuperaPelota(Model* model);
     char getCodigoComando();
    virtual ~RecuperaPelota();
    void execute();
protected:

private:
    Model* model;
};

#endif // RECUPERAPELOTA_H
