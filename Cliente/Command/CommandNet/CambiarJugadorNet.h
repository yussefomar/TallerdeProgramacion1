#ifndef CAMBIARJUGADORNET_H
#define CAMBIARJUGADORNET_H

#include "../CommandNet.h"
#include "../Model/Model.h"

class CambiarJugadorNet : public CommandNet
{
public:
    CambiarJugadorNet(Model* model);
    virtual ~CambiarJugadorNet();
    void  execute();
    char  getCodigoComando();
    CommandNet* getCopia();

protected:

private:
};

#endif // CAMBIARJUGADORNET_H
