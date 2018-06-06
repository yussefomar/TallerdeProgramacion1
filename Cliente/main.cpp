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

int main(int argc, char* args[])
{
    common.backupFile();
    common.createFile();
    Util_LoggerObserver loggerObserver(3);
    try
    {
        Model model;
        Util_Configuracion configuracion(&model, &loggerObserver);
        model.agregarObservador(&loggerObserver);

        ModeloCliente modelCliente(&model);
        LogIn logIn(&modelCliente);

        if(!logIn.puedeArrancar) return 0;

        View view(&model);
        view.Attach(&loggerObserver);

        model.agregarObservador(&view);

        Controller controller(&modelCliente);
        controller.Attach(&loggerObserver);

        modelCliente.recibirRespuestaInicio();
        while( !controller.quitPressed())
        {
            modelCliente.enviarBackup();
            modelCliente.recibirBackup();
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
        loggerObserver.writeErrorLine("Ha ocurrido un runtime error en main: ", "main.cpp");
        loggerObserver.writeErrorLine(re.what(), "main.cpp");
    }
    catch(const std::exception& ex)
    {
        loggerObserver.writeErrorLine("Ha ocurrido un error en main: ", "main.cpp");
        loggerObserver.writeErrorLine(ex.what(), "main.cpp");
    }
    catch(...)
    {
        loggerObserver.writeErrorLine("Error desconocido que no se ha podido especificar.", "main.cpp");
    }



}
