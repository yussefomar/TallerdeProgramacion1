#ifndef CLIENTE_H
#define CLIENTE_H

#include "Buffer.h"
#include <list>
#include "../SocketServidor/SocketServidor.h"
#include <vector>
#include <thread>
#include <mutex>
#include <queue>

#define LI_NOMBRE_OK 0X0B //NOMBRE CORRECTO.
#define LI_NOMBRE_ERROR 0X0C //NOMBRE INCORRECTO.
#define LI_NOMBRE_REPETIDO 0X0D //NOMBRE EXISTENTE.
#define LI_CREDENCIALES_OK 0X0E //CREDENCIALES CORRECTAS.
#define LI_CREDENCIALES_ERROR 0X0F //CREDENCIALES INCORRECTAS.
#define LI_CONSULTO_INICIO 0X11 //ME PREGUNTAN SI SE INICIO.
#define LI_INICIO_OK 0X12 //RESPONDO QUE ESTAN TODOS CONECTADOS.

class Cliente
{
public:
    Cliente();
    virtual ~Cliente();

    void setIPPuerto(std::string ip, std::string puerto);
    void setBuffer(Buffer* buffer);
    void setBDD(std::vector<char> bdd);
    void setCantidadClientes(unsigned cantidad);

    void aceptarCliente();

    void recibirMensaje();
    void enviarMensaje();
    bool estaConectado();
    void permitirInicio();
    void enviarARenderizar();
    void avisarDesconexion();

    unsigned getIdCliente();
    unsigned getCantidadClientes();
    char getCredencial();

    void enviarPedidoBackup();
    std::string recibirBackup();
    void enviarBackup(std::string backup);
    void setSocket(SocketServidor* socket);


protected:

private:
    static std::queue<char> usuariosIngresados;
    static std::mutex mutexIngresos;
    static int contadorClientes;

    unsigned idCliente;
    Buffer* buffer;
    SocketServidor* socket;
    std::string ip;
    std::string puerto;
    std::vector<char> bdd;
    char credencial;
    unsigned cantidadClientes;

};

#endif // CLIENTE_H
