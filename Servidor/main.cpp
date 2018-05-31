#include <string.h>
#include <iostream>
#include <chrono>
#include <thread>

#include <ModeloServidor.h>
#include "../Utils/Util_Configuracion.h"

using namespace std;

#define CANTCLT 2

void modoMultiJugador();
void modoSingleJugador();

int main(int argc, char* args[])
{
    //modoSingleJugador();
    //Util_Configuracion configuracion;
    modoMultiJugador();

    return 0;

}

void modoMultiJugador()
{
    /*Aun no esta preparado, ni muy pensado*/
    std::cout << "server run" << std::endl;
    ModeloServidor modeloServidor;
    Util_Configuracion configuracion(&modeloServidor);
    modeloServidor.aceptarClientesEntrantes();
    modeloServidor.recibirInformacion();
    modeloServidor.enviarOKInicio();
    modeloServidor.tratarNuevosClientes();
    std::cout << "server with clients" << std::endl;
    unsigned i = 0;

    while(modeloServidor.clientesEstanConectados())
    {
        modeloServidor.recibirMensajes();
        modeloServidor.enviarMensajes();

        std::cout << "server send msg" << std::endl;
        std::cout << "ciclo nro: " << i << std::endl;
        ++i;
    }
}

void modoSingleJugador()
{
//    std::cout << "server run" << std::endl;
//    Buffer buffer(1);
//    Cliente cliente(&buffer);
//    std::cout << "server with clients" << std::endl;
//    int i = 0;
//    while(cliente.estaConectado())
//    {
//        cliente.recibirMensaje();
//        cliente.enviarMensaje();
//        ++i;
//        std::cout << "Termino el Ciclo nro: " << i << std::endl;
//    }
//
//    std::cout << "Server desconectado" << std::endl;

}
