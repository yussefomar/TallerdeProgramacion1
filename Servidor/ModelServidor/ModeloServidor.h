#ifndef MODELOSERVIDOR_H
#define MODELOSERVIDOR_H

#include "Cliente.h"
#include <vector>
#include <thread>
#include <mutex>
#include "Reconector.h"
/*#include "Buffer.h"*/

class ModeloServidor
{
public:
    ModeloServidor();
    virtual ~ModeloServidor();

    void aceptarClientes();
    void generarReconectores();

    void enviarMensajes();
    void recibirMensajes();

    bool clientesEstanConectados();

    char hashear(std::string unString);

    void setClientesPermitidos(unsigned cantidadMaxClientes);
    void setIpYPuerto(std::string ip, std::string puerto);
    void permitirInicio();
    void enviarARenderizar();
    void setBDD(std::vector<char> bdd);
    void lanzarHiloDeReconexion();
    void hiloDeAnalisisDeReconexion();

    void enviarBackup();
    void recibirBackup();

protected:

private:
    Buffer buffer;
    std::vector<Cliente> clientes;
    std::queue<char> clientesIngresados;
    std::vector<char> bdd;

    std::vector<Reconector> reconectores;
    std::string ip;
    std::string puerto;
    std::thread hiloDeReconexion;
    std::mutex mutexReconexion;
    std::vector<std::string> backups;
    unsigned backupElegido;



};

#endif // MODELOSERVIDOR_H
