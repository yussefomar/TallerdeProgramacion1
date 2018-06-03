#ifndef DEFINIRCOMOLOCAL_H
#define DEFINIRCOMOLOCAL_H

#include <CommandNet.h>


class DefinirComoLocal : public CommandNet
{
public:
    DefinirComoLocal(Model* model);
    virtual ~DefinirComoLocal();
    void  execute() ;
    char  getCodigoComando() ;
CommandNet* getCopia();
protected:

private:
};

#endif // DEFINIRCOMOLOCAL_H
