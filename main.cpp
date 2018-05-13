#include <iostream>

#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include "Utils/Util_LoggerObserver.h"
//#include "Utils/Util_Persitencia.h"
#include "Utils/Util_Common.h"
#include "Utils/IObserver.h"
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "Network/ModeloCliente.h"
#include "View/View.h"
#include "View/View_Loguin.h"
#include "Utils/Util_Configuracion.h"

Util_Common common;

void modoOffline();
void modoOnline();

int main(int argc, char* args[])
{
    modoOffline();
    return 0;
}

void modoOnline()
{
    // Hacemos un backup del log de la ejecucion anterior.
    common.backupFile();
    // Hacemos un log de la ejecucion anterior.
    common.createFile();
    // Creamos el logger con el nivel más bajo.
    Util_LoggerObserver loggerObserver(3);

    Model model;
    model.Attach(&loggerObserver);

    Util_Configuracion configuracion(&model, &loggerObserver);
//    Util_Persistencia  persistencia(&model, &loggerObserver);

    /***********************************************************************************/
    /**EJEMPLO**/
    /***********************************************************************************/
    /*
    std::string temp = "";
    View_Loguin loguin(1);
    temp = loguin.procesar();

    cout << "=================================================================\n";
    cout << " El usuario se intentó loguear con la siguiente información: \n";
    cout << "=================================================================\n";
    cout << temp;
    cout << "\n=================================================================\n";
    */
    /***********************************************************************************/
    /***********************************************************************************/
    View view(&model);
    view.Attach(&loggerObserver);

    ModeloCliente modelCliente(&model);
    Controller controller(&modelCliente);
    controller.Attach(&loggerObserver);



    while( !controller.quitPressed() )
    {
        controller.processInput();
        modelCliente.update();
        view.render();
    }
}

void modoOffline()
{
    // Hacemos un backup del log de la ejecucion anterior.
    common.backupFile();
    // Hacemos un log de la ejecucion anterior.
    common.createFile();
    // Creamos el logger con el nivel más bajo.
    Util_LoggerObserver loggerObserver(3);

    Model model;
    model.Attach(&loggerObserver);

    Util_Configuracion configuracion(&model, &loggerObserver);
//    Util_Persistencia  persistencia(&model, &loggerObserver);

    /***********************************************************************************/
    /**EJEMPLO**/
    /***********************************************************************************/
    /*
    std::string temp = "";
    View_Loguin loguin(1);
    temp = loguin.procesar();

    cout << "=================================================================\n";
    cout << " El usuario se intentó loguear con la siguiente información: \n";
    cout << "=================================================================\n";
    cout << temp;
    cout << "\n=================================================================\n";
    */
    /***********************************************************************************/
    /***********************************************************************************/
    View view(&model);
    view.Attach(&loggerObserver);

    Controller controller(&model);
    controller.Attach(&loggerObserver);

    //MSPORUPDATE CONTROLA EN CIERTA FORMA EL FPS DEL JUEGO... NO SE ASUSTEN
    long double MSPORUPDATE = 0.7;
    long double tiempoActual = 0.0;
    long double lapsoDeTiempo = 0.0;
    long double tiempoPrevio = clock();
    long double lag = 0.0;

    while( !controller.quitPressed() )
    {
        tiempoActual = clock();
        lapsoDeTiempo = (tiempoActual - tiempoPrevio) / (CLOCKS_PER_SEC / 1000);
        tiempoPrevio = tiempoActual;
        lag += lapsoDeTiempo;

        controller.processInput();

        while (lag >= MSPORUPDATE)
        {
            model.update();
            lag -= MSPORUPDATE;
        }

        view.render();
    }
}

