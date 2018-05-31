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
        std::vector<User> users = parser.GetUsuarios();
        int cantidadClientes = parser.GetCantidadClientes();
        Conexion conexion = parser.getIpPuerto();
        //METODOS PARA CONFIGURAR EL MODEL
        //this->model->SetUsuarios(users);
        this->modeloServidor = model;
        this->modeloServidor->setClientesPermitidos(cantidadClientes);
        this->modeloServidor->usuariosNombre = std::vector<char>(users.size());//(users.size());
        this->modeloServidor->usuariosPassword = std::vector<char>(users.size());
        this->modeloServidor->setIpYPuerto(conexion.get_ip(), conexion.get_puerto());
        for(unsigned j = 0; j < users.size(); ++j)
        {
            this->modeloServidor->usuariosNombre[j] = this->modeloServidor->hashear(users[j].get_name());
            this->modeloServidor->usuariosPassword[j] = this->modeloServidor->hashear(users[j].get_password());
        }
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




