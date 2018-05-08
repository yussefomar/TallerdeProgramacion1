#include <iostream>

#include "Utils/Util_LoggerObserver.h"
//#include "Utils/Util_Persitencia.h"
#include "Utils/Util_Common.h"
#include "Utils/IObserver.h"
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "Network/ModeloCliente.h"
#include "View/View.h"


using namespace std;

Util_Common common;

int main(int argc, char* args[])
{
    // Hacemos un backup del log de la ejecucion anterior.
    common.backupFile();
    // Hacemos un log de la ejecucion anterior.
    common.createFile();
    // Creamos el logger con el nivel más bajo.
    Util_LoggerObserver loggerObserver(3);

    Model model;
    model.Attach(&loggerObserver);

   // Util_Configuracion configuracion(&model, &loggerObserver);
//    Util_Persistencia  persistencia(&model, &loggerObserver);

    View view(&model);
    view.Attach(&loggerObserver);

    /*Para Modo offline, descomentar estas lineas y comentar
    las del modo online*/
    Controller controller(&model);
    controller.Attach(&loggerObserver);

    /*Para Modo online, descomentar estas lineas y comentar
    las del modo offline*/
    //ModeloCliente modelCliente(&model);
    //Controller controller(&modelCliente);
    //controller.Attach(&loggerObserver);

    while( !controller.quitPressed() )
    {
        controller.processInput();
        model.update();
        view.render();
    }
    //delete loggerObserver;
    return 0;
}

