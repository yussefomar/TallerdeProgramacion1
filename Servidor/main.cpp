#include <string.h>
#include <iostream>
#include <chrono>
#include <thread>

#include <ModeloServidor.h>
#include "../Utils/Util_Configuracion.h"

using namespace std;

int main(int argc, char* args[])
{
    std::cout << "server run" << std::endl;
    ModeloServidor modeloServidor;
    Util_Configuracion configuracion(&modeloServidor);
    modeloServidor.aceptarClientesEntrantes();
    modeloServidor.recibirInformacion();
    modeloServidor.enviarOKInicio();
    modeloServidor.tratarNuevosClientes();
    std::cout << "server with clients" << std::endl;
    unsigned i = 0;

    //MSPORUPDATE CONTROLA EN CIERTA FORMA EL FPS DEL JUEGO... NO SE ASUSTEN
    long double MSPORUPDATE = 0.7;
    long double tiempoActual = 0.0;
    long double lapsoDeTiempo = 0.0;
    long double tiempoPrevio = clock();
    long double lag = 0.0;

    while(modeloServidor.clientesEstanConectados())
    {
        tiempoActual = clock();
        lapsoDeTiempo = (tiempoActual - tiempoPrevio) / (CLOCKS_PER_SEC / 1000);
        tiempoPrevio = tiempoActual;
        lag += lapsoDeTiempo;

        modeloServidor.recibirMensajes();
        while (lag >= MSPORUPDATE)
        {
            modeloServidor.enviarMensajes();
            modeloServidor.recibirMensajes();
            lag -= MSPORUPDATE;
        }
        modeloServidor.enviarARenderizar();
        std::cout << "ciclo nro: " << i << std::endl;
        ++i;
    }
    return 0;

}
