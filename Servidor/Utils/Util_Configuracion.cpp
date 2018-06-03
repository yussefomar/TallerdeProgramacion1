#include <yaml-cpp/yaml.h>
#include <yaml-cpp/exceptions.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include "../Utils/Util_Configuracion.h"
#include "../ModelServidor/ModeloServidor.h"

Util_ParserUsuario parser;
/**ModeloServidor* model, Util_LoggerObserver* loggerObserver**/
Util_Configuracion::Util_Configuracion(ModeloServidor* model)
{
//   this->Attach(loggerObserver);
//   parser.Attach(loggerObserver);
    try
    {
        this->modeloServidor = model;
        std::vector<User> users = parser.GetUsuarios();
        int cantidadClientes = parser.GetCantidadClientes();
        Conexion conexion = parser.getIpPuerto();
        this->modeloServidor->setClientesPermitidos(cantidadClientes);
        this->modeloServidor->setIpYPuerto(conexion.get_ip(), conexion.get_puerto());

        //METODOS PARA CONFIGURAR EL MODEL

        std::vector<char> bdd = std::vector<char>(users.size());
        for(unsigned i = 0; i < users.size(); ++i)
        {
            bdd[i] = this->modeloServidor->hashear(users[i].get_name() + users[i].get_password());
        }

        this->modeloServidor->setBDD(bdd);
    }
    catch(...)
    {
        // NotifyError("Error desconocido que no se ha podido especificar.", "Util_Configuracion.cpp");
    }
}

void Util_Configuracion::close()
{

}

Util_Configuracion::~Util_Configuracion()
{
    this->close();
}




