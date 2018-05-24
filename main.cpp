#include <iostream>

#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include "Utils/Util_LoggerObserver.h"
#include "Utils/Util_Common.h"
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

try
{
    /**
    bool quit = false;
    View_Loguin loguinScreen(1);
    InformacionIngreso informacionIngreso(false);
    if(!loguinScreen.Inicializar()) return -1;
    while( quit == false )
    {
        loguinScreen.Procesar(informacionIngreso);
        //a modo de ejemplo, supongamos que luego de loguearnos hubo algo mal.
        informacionIngreso.mensaje = "mal ingreso de datos";
        informacionIngreso.error = false;
    }
    loguinScreen.Cerrar();
    **/
    modoOnline();
    //modoOffline();
    return 0;

     }
    catch(const std::runtime_error& re)
    {
//        NotifyError("Error en Runtime: ", "View.cpp");
//        NotifyError(re.what(), "View.cpp");
    }
    catch(const std::exception& ex)
    {
//        NotifyError("Ha ocurrido un error: ", "View.cpp");
//        NotifyError(ex.what(), "View.cpp");
    }
    catch(...)
    {
//        NotifyError("Error desconocido que no se ha podido especificar.", "View.cpp");
    }


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
    Util_Configuracion configuracion(&model, &loggerObserver);
    model.agregarObservador(&loggerObserver);

    ModeloCliente modelCliente(&model);

    /***********************************************************************************/
    /**EJEMPLO**/
    /***********************************************************************************/
    /**
    bool quit = false;
    char respuesta;
    View_Loguin loguinScreen(1);
    InformacionIngreso informacionIngreso(false);
    loguinScreen.Inicializar();
    while( quit == false )
    {
        loguinScreen.Procesar(informacionIngreso);
        if(informacionIngreso.equipoIngresado) modelCliente.enviarMensajeLogin();
        respuesta = modelCliente.recibirMensajeLogin();
        informacionIngreso.procesarRespuesta(respuesta);
    }
    loguinScreen.Cerrar();
    **/
    /***********************************************************************************/
    /***********************************************************************************/


    View view(&model);
    view.Attach(&loggerObserver);

    Controller controller(&modelCliente);
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
            modelCliente.update();
            lag -= MSPORUPDATE;
        }

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
    Util_Configuracion configuracion(&model, &loggerObserver);
    model.agregarObservador(&loggerObserver);

    View view(&model);
    view.Attach(&loggerObserver);

    Controller controller(&model);
    controller.Attach(&loggerObserver);

    //MSPORUPDATE CONTROLA EN CIERTA FORMA EL FPS DEL JUEGO... NO SE ASUSTEN
    long double MSPORUPDATE = 0.3;
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

