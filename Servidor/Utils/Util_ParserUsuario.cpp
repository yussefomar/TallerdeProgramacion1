#include <yaml-cpp/yaml.h>
#include <yaml-cpp/exceptions.h>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;

#include "../Utils/Util_ParserUsuario.h"

std::vector<User> users;
std::vector<Servidor> servidor;
std::vector<Conexion> conexion;

std::vector<User> Util_ParserUsuario::read_yaml_Usuario()
{

    std::vector<YAML::Node> baseNode = YAML::LoadAllFromFile("./Config/Usuarios.yaml");


    for (auto &document : baseNode)
    {
        std::for_each(document["users"].begin(), document["users"].end(), [&users](YAML::Node user)
        {
            users.emplace_back(user);
        });
    }
    return users;

}

std::vector<User> Util_ParserUsuario::GetUsuarios()
{
    try
    {
        this->read_yaml_Usuario();
    }
    catch(YAML::Exception ex)
    {
        //NotifyError("llenarParametrosObtenidos: no se pudo obtener el nodo xxxxxx", "Util_ParserUsuario.cpp");
        // parametrosObtenidos.esValido = 0;
    }
            return users;


}

Servidor Util_ParserUsuario::read_yaml_CantidadClientes()
{
    std::vector<YAML::Node> baseNode = YAML::LoadAllFromFile("./Config/Usuarios.yaml");
    servidor.clear();
    for (auto &document : baseNode)
    {
        servidor.emplace_back(document["servidor"]);
    }
    return servidor.at(0);

}

int Util_ParserUsuario::GetCantidadClientes()
{
    try
    {
        Servidor unServidor = this->read_yaml_CantidadClientes();
                    return std::stoi(unServidor.get_cantidadClientes());

    }
    catch(YAML::Exception ex)
    {
        //NotifyError("llenarParametrosObtenidos: no se pudo obtener el nodo xxxxxx", "Util_ParserUsuario.cpp");
        // parametrosObtenidos.esValido = 0;
    }
    return -1;

}

Conexion Util_ParserUsuario::read_yaml_Conexion()
{

    std::vector<YAML::Node> baseNode = YAML::LoadAllFromFile("./Config/Usuarios.yaml");
    conexion.clear();
    for (auto &document : baseNode)
    {
        conexion.emplace_back(document["conexion"]);
    }
    return conexion.at(0);
}

Conexion Util_ParserUsuario::getIpPuerto()
{
    try
    {
        this->read_yaml_Conexion();
    }
    catch(YAML::Exception ex)
    {
        //NotifyError("llenarParametrosObtenidos: no se pudo obtener el nodo xxxxxx", "Util_ParserUsuario.cpp");
        // parametrosObtenidos.esValido = 0;
    }
            return conexion.at(0);


}
