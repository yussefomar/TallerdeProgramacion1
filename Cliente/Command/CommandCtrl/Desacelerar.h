#ifndef DESACELERAR_H
#define DESACELERAR_H

#include "CommandCtrl.h"

class Desacelerar : public CommandCtrl
{
public:
    Desacelerar(Model* model);
    virtual ~Desacelerar();
    void execute();
    char getCodigoComando();

protected:

private:
};

#endif // DESACELERAR_H
