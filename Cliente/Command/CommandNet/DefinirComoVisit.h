#ifndef DEFINIRCOMOVISIT_H
#define DEFINIRCOMOVISIT_H

#include <CommandNet.h>


class DefinirComoVisit : public CommandNet
{
public:
    DefinirComoVisit(Model* model);
    virtual ~DefinirComoVisit();
    void  execute() ;
    char  getCodigoComando() ;
     CommandNet* getCopia();


protected:

private:
};

#endif // DEFINIRCOMOVISIT_H
