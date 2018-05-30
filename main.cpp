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

Util_Common common; //Porque importa esta variable global

void modoOffline();
void modoOnline();

int main(int argc, char* args[])
{
    try
    {
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
    //modelCliente.conectarConServer("192.168.0.29", "8080");
    //modelCliente.setComoVisitante();

    char respuesta;
    View_Loguin loguinScreen(1);
    InformacionIngreso informacionIngreso(false);
    loguinScreen.Inicializar();

    while( !informacionIngreso.ipIngresado || !informacionIngreso.puertoIngresado )
    {
        loguinScreen.Procesar(informacionIngreso);
        if(informacionIngreso.ipIngresado && informacionIngreso.puertoIngresado )
        {
            modelCliente.conectarConServer(informacionIngreso.ip, informacionIngreso.puerto);
            informacionIngreso.procesarConectividad(modelCliente.conectadoAlServer());
            //===========================================================================
            //informacionIngreso.procesarConectividad(false);
            //===========================================================================
        }
    }

    while( !informacionIngreso.nombreIngresado )
    {
        loguinScreen.Procesar(informacionIngreso);
        if(informacionIngreso.nombreIngresado)
        {
            modelCliente.enviarNombre(informacionIngreso.nombre);
            respuesta = modelCliente.recibirValidacionNombre();
            informacionIngreso.procesarRespuesta(respuesta);
            //===========================================================================
            //informacionIngreso.procesarRespuesta(0X0B);
            //===========================================================================
        }
    }

    while( !informacionIngreso.passwordIngresado )
    {
        loguinScreen.Procesar(informacionIngreso);
        if(informacionIngreso.passwordIngresado)
        {
            modelCliente.enviarPassword(informacionIngreso.password);
            respuesta = modelCliente.recibirValidacionPassword();
            informacionIngreso.procesarRespuesta(respuesta);
            //===========================================================================
            //informacionIngreso.procesarRespuesta(0X0F);
            //===========================================================================
        }
    }

    while( !informacionIngreso.equipoIngresado )
    {
        loguinScreen.Procesar(informacionIngreso);
        if(informacionIngreso.equipoIngresado) {
            if(informacionIngreso.equipo == "1") {
                modelCliente.setComoLocal();
            }else if(informacionIngreso.equipo == "2") {
                modelCliente.setComoVisitante();
            }else {
                informacionIngreso.equipoErroneo();
            }
        }
    }

    /**CORROBORAR SI ESTO VA BIEN PARA HACER LA ESPERA MIENTRAS SE CONECTAN TODOS.**/
//    informacionIngreso.mensaje = "A la espera de que todos los jugadores se conecten.";
//    while(informacionIngreso.espera)
//    {
//        loguinScreen.Procesar(informacionIngreso);
//        modelCliente.consultarInicio();
//        informacionIngreso.espera = !modelCliente.recibirRespuestaInicio();
//    }

    loguinScreen.Cerrar();

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

