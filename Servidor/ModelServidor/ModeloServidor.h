#ifndef MODELOSERVIDOR_H
#define MODELOSERVIDOR_H

#include <vector>
#include "Cliente.h"
#include "TratarClientesNuevos.h"
/*#include "Buffer.h"*/

class ModeloServidor
{
public:
    ModeloServidor();
    virtual ~ModeloServidor();
    void enviarMensajes();
    void recibirMensajes();
    void aceptarClientesEntrantes();
    void tratarNuevosClientes();
    bool clientesEstanConectados();
    bool hayCambiosPorEnviar();
    void recibirInformacion();
    bool verificarUsuario(char usuario, unsigned i);
    bool verificarPassword(char usuario, char password, unsigned i);
    char hashear(std::string unString);
    std::vector<char> usuariosNombre;
    std::vector<char> usuariosPassword;
    void setClientesPermitidos(unsigned cantidadMaxClientes);
    void setIpYPuerto(std::string ip, std::string puerto);
    void enviarOKInicio();

protected:

private:
    Buffer* buffer;
    TratarClientesNuevos* tratarClientes;
    std::vector<Cliente*> clientes;
    //int cantidadClientes;
    std::string ip;
    std::string puerto;
};

#endif // MODELOSERVIDOR_H
