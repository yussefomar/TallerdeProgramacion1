#include <iostream>

#include "Utils/Util_LoggerObserver.h"
#include "Utils/Util_Parser.h"
#include <yaml-cpp/yaml.h>

#include "Model.h"
#include "Controller.h"
#include "View.h"
//Solo para probar hasta que pueda manejar el logg y parser
#include "Formacion312.h"
#include "Formacion33.h"
#include "Formacion321.h"
#include "Utils/IObserver.h"



//unsigned short logLevel;
using namespace std;
//Util_Logger logger;
Util_Parser parser;
const std::string pathDefaultConfig = "./Configs/config.yaml";

int main(int argc, char* args[])
{
    Parametros parametrosParseado = parser.read_yaml_Parametros("./Configs/configIndicado.yaml",pathDefaultConfig);
    Util_LoggerObserver* loggerObserver = new Util_LoggerObserver(3);
    Model model;
    Formacion321 f;
    model.Attach(loggerObserver);
    //Solo hasta que pueda manejar logger, esto es un asco.
    model.setFormacion(&f);
    View view(&model);
    Controller controller(&model);

    while( !controller.quitPressed() )
    {
        controller.processInput();
        model.update();
        view.render();
    }


    return 0;

}
