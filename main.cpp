#include <iostream>

#include "Utils/Util_Logger.h"
#include "Utils/Util_Parser.h"
#include <yaml-cpp/yaml.h>

#include "Model.h"
#include "Controller.h"
#include "View.h"


//unsigned short logLevel;
using namespace std;
Util_Logger logger;
Util_Parser parser;



int main(int argc, char* args[])
{
    /********************************************************************************************/
    Equipo equipoParseado = parser.read_yaml_Equipo("./Configs/config.yaml");
    Debug debugParseado = parser.read_yaml_Debug("./Configs/config.yaml");
    logger.createFile(3);
    /**
    Si queremos usar el logger mientras leemos el archivo de configuracion debemos crearlo como
    arriba, luego podemos llamar al método updateLevel para ponerle el nivel que corresponda.

    En cualquier parte del código que querramos usar el logger podemos llamar a los siguientes
    métodos según corresponda, luego según el level del logger, escribirá o no en el archivo.
    por ejemplo en un catch donde saltó una excepción ponemos log.writeErrorLine y si el level
    está configurado para escribir errores los pondra en el archivo.
    **/
    logger.writeErrorLine("Ejemplo de Error." + equipoParseado.get_formacion()); //nivel bajo, siempre mostramos errores.
    logger.writeWarningLine("Ejemplo de Warning." + equipoParseado.get_casaca()); //nivel medio, mostramos errores y warnings.
    logger.writeMessageLine("Ejemplo de linea común." + debugParseado.get_level()); //nivel alto, se escribe todo.
    /********************************************************************************************/

    /********************************************************************************************/


    Model model;
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
