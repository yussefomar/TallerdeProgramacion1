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
    void setMutexReconexion(std::mutex* mutexReconexion);
    void enviarBackup(std::string backup);

protected:

private:
    Cliente* cliente;
    std::mutex* mutexReconexion;
    bool listoParaReconexion;
    SocketServidor* socketReconexion;


};

#endif // RECONECTOR_H
