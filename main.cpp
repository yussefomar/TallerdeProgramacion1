#include <iostream>

#include "Utils/Util_Logger.h"
#include "Utils/Util_Parser.h"
#include <yaml-cpp/yaml.h>

#include "Model.h"
#include "Controller.h"
#include "View.h"
//Solo para probar hasta que pueda manejar el logg y parser
#include "Formacion312.h"
#include "Formacion33.h"
#include "Formacion321.h"



//unsigned short logLevel;
using namespace std;
Util_Logger logger;
Util_Parser parser;
const std::string pathDefaultConfig = "./Configs/config.yaml";


int main(int argc, char* args[])
{
    /********************************************************************************************/
   //primer parametros se levanta desde consola
    Parametros parametrosParseado = parser.read_yaml_Parametros("./Configs/configIndicado.yaml",pathDefaultConfig);
    logger.createFile(3);
    /**
    Si queremos usar el logger mientras leemos el archivo de configuracion debemos crearlo como
    arriba, luego podemos llamar al método updateLevel para ponerle el nivel que corresponda.

    En cualquier parte del código que querramos usar el logger podemos llamar a los siguientes
    métodos según corresponda, luego según el level del logger, escribirá o no en el archivo.
    por ejemplo en un catch donde saltó una excepción ponemos log.writeErrorLine y si el level
    está configurado para escribir errores los pondra en el archivo.
    **/
    //logger.writeErrorLine("Ejemplo de Error." + equipoParseado.get_formacion()); //nivel bajo, siempre mostramos errores.
    //logger.writeWarningLine("Ejemplo de Warning." + equipoParseado.get_casaca()); //nivel medio, mostramos errores y warnings.
    //logger.writeMessageLine("Ejemplo de linea común." + debugParseado.get_level()); //nivel alto, se escribe todo.
    /********************************************************************************************/

    /********************************************************************************************/


    Model model;
    Formacion321 f;
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
