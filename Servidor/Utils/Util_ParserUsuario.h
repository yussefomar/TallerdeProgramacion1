#ifndef UTIL_PARSERUSUARIO_H_
#define UTIL_PARSERUSUARIO H_

#include <iostream>
#include <string>
#include <list>
#include <yaml-cpp/yaml.h>


using namespace std;

class Servidor
{
public:
    Servidor(const YAML::Node &node) :
        cantidadClientes(node["cantidadCli"].as<std::string>()) {};
    std::string const &get_cantidadClientes() const
    {
        return cantidadClientes;
    };
private:
    std::string cantidadClientes;
};

class User
{
public:
    User(const YAML::Node &node) :
        name(node["name"].as<std::string>()),
        password(node["password"].as<std::string>()) {};
    std::string const &get_name() const
    {
        return name;
    };
    std::string const &get_password() const
    {
        return password;
    };
private:
    std::string name;
    std::string password;
};

class Conexion
{
public:
    Conexion(const YAML::Node &node) :
        ip(node["ip"].as<std::string>()),
        puerto(node["puerto"].as<std::string>()) {};
    std::string const &get_ip() const
    {
        return ip;
    };
    std::string const &get_puerto() const
    {
        return puerto;
    };
private:
    std::string ip;
    std::string puerto;
};

class Util_ParserUsuario
{
public:
    std::vector<User> GetUsuarios();
    int GetCantidadClientes();
    Conexion  getIpPuerto();
    Servidor read_yaml_CantidadClientes();
    Conexion read_yaml_Conexion();
    std::vector<User> read_yaml_Usuario();
private:



};



#endif
