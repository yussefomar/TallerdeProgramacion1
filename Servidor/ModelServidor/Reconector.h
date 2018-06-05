#ifndef RECONECTOR_H
#define RECONECTOR_H

#include "Cliente.h"

class Reconector
{
public:
    Reconector();
    virtual ~Reconector();

    void setCliente(Cliente* cliente);
    bool analizarSocketReconexion(SocketServidor* socketReconexion);

protected:

private:
    Cliente* cliente;

};

#endif // RECONECTOR_H
