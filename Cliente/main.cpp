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
#include "LogIn.h"

Util_Common common; //Porque importa esta variable global


int main(int argc, char* args[]) try
{
    common.backupFile();
    common.createFile();
    Util_LoggerObserver loggerObserver(3);

    Model model;
    Util_Configuracion configuracion(&model, &loggerObserver);
    model.agregarObservador(&loggerObserver);

    ModeloCliente modelCliente(&model);
    LogIn logIn(&modelCliente);

    View view(&model);
    view.Attach(&loggerObserver);

    Controller controller(&modelCliente);
    controller.Attach(&loggerObserver);
    modelCliente.recibirRespuestaInicio();

    while( !controller.quitPressed())
    {
        controller.processInput();

        while (!model.necesitaRenderizar())
        {
            modelCliente.update();
        }

        view.render();
    }
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



