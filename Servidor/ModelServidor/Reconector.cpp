#include "Reconector.h"

#include <iostream>

Reconector::Reconector()
{
    this->listoParaReconexion = false;
}

Reconector::~Reconector()
{
    //dtor
}


void Reconector::setCliente(Cliente* cliente)
{
    this->cliente = cliente;
}

void Reconector::setMutexReconexion(std::mutex* mutexReconexion)
{
    this->mutexReconexion = mutexReconexion;
}

bool Reconector::analizarSocketReconexion(SocketServidor* socketReconexion)
{
    if(this->cliente->estaConectado())
        return false;

    socketReconexion->enviarByte(this->cliente->getIdCliente());
    socketReconexion->enviarByte(this->cliente->getCantidadClientes());

    std::cout << "VERIFICAR CREDENCIALES" << std::endl;
    char credencial;
    bool credencialesValidas = false;
    credencial = socketReconexion->recibirByte();

    while(!credencialesValidas)
    {
        credencialesValidas = this->cliente->getCredencial() == credencial;
        if(!credencialesValidas)
        {
            socketReconexion->enviarByte(LI_CREDENCIALES_ERROR);
            credencial = socketReconexion->recibirByte();
        }
    }


    socketReconexion->enviarByte(LI_CREDENCIALES_OK);
    socketReconexion->enviarByte(LI_INICIO_OK);
    //IMPORTANTE PARA CUANDO EL MODELO SERVIDOR PREGUNTA SI NOS PODEMOS RECONECTAR
    this->mutexReconexion->lock();
    this->listoParaReconexion = true;
    this->cliente->enviarPedidoBackup();
    this->socketReconexion = socketReconexion;
    this->mutexReconexion->unlock();
    return true;
}

void Reconector::enviarBackup(std::string backup)
{
    std::string backupNulo = "";
    if(this->listoParaReconexion)
    {
        if(backup.size())
        {
            this->cliente->setSocket(this->socketReconexion);
            this->cliente->enviarBackup(backup);
            this->socketReconexion = nullptr;
            this->listoParaReconexion = false;
        }
    }
    else
    {
        this->cliente->enviarBackup(backupNulo);
    }
}
