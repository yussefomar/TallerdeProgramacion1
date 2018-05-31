#ifndef ACELERAR_H
#define ACELERAR_H

#include "CommandCtrl.h"

class Acelerar : public CommandCtrl
{
public:
    Acelerar(Model* model);
    virtual ~Acelerar();
    void execute();
    char getCodigoComando();


protected:

private:
};

#endif // ACELERAR_H
