#include "Reconector.h"



Reconector::Reconector()
{

}

Reconector::~Reconector()
{
    //dtor
}


void Reconector::setCliente(Cliente* cliente) {
    this->cliente = cliente;
}

bool Reconector::analizarSocketReconexion(SocketServidor* socketReconexion) {
    return false;
}
