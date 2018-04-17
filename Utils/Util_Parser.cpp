#include <yaml-cpp/yaml.h>
#include  <yaml-cpp/exceptions.h>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>


using namespace std;

#include "Util_Parser.h"
#include "Util_Logger.h"

std::vector<Equipo> equipos;
std::vector<Debug> debugs;


inline bool Util_Parser::fileExists(const std::string& name)
{
    ifstream f(name.c_str());
    if (f.good()){
    f.close();
    return true;
    } else {
    f.close();
    return false;
    }
}

//pasar por referencia
inline bool Util_Parser::levelValido(std::string &name){

//TODO: hacer alguna comprobacion para el size.
//tu upper
char c1[100];
for(int i = 0; i<name.size(); i++)
{
name.at(i) = toupper(name.at(i));
c1[i] = name.at(i);
}

char c2[] = "DEBUG";
char c3[] = "INFO";
char c4[] = "ERROR";

    if((strncasecmp(c1,c2,2))==0){
    name = "debug";
    return true;}

    if((strncasecmp(c1,c3,2))==0){
    name = "info";
    return true;}

    if((strncasecmp(c1,c4,2))==0){
    name = "error";
    return true;}

    name = "";
    return false;

}
//pasar por referencia
inline bool Util_Parser::casacaValido(std::string &name){
//TODO: hacer alguna comprobacion para el size.
//tu upper
char c1[100];
for(int i = 0; i<name.size(); i++)
{
name.at(i) = toupper(name.at(i));
c1[i] = name.at(i);
}

char c2[] = "PRINCIPAL";
char c3[] = "SUPLENTE";
 if((strncasecmp(c1,c2,2))==0){
    name = "principal";
    return true;}

    if((strncasecmp(c1,c3,2))==0){
    name = "suplente";
    return true;}
    name = "";
return false;
}
//pasar por referencia
 inline bool Util_Parser::formacionValido(std::string &name){
//TODO: hacer alguna comprobacion para el size.
//tu upper
char c1[100];
for(int i = 0; i<name.size(); i++)
{
c1[i] = name.at(i);
}
char c2[] = "3-3";
char c3[] = "3-1-2";
char c4[] = "3-2-1";
    if((strncasecmp(c1,c2,3))==0){
    name = "3-3";
    return true;}

    if((strncasecmp(c1,c3,3))==0){
    name = "3-1-2";
    return true;}

    if((strncasecmp(c1,c4,3))==0){
    name = "3-2-1";
    return true;}
    name = "";
    return false;
}

Equipo Util_Parser::read_yaml_Equipo(std::vector<YAML::Node> baseNode)
{
equipos.clear();
	for (auto &document : baseNode)
    {
        equipos.emplace_back(document["equipo"]);
    }
    return equipos.at(0);
}

Debug Util_Parser::read_yaml_Debug(std::vector<YAML::Node> baseNode)
{
debugs.clear();
    for (auto &document : baseNode)
    {
        debugs.emplace_back(document["debug"]);
    }
    return debugs.at(0);

}



Parametros Util_Parser::read_yaml_Parametros(std::string pathIndicado, std::string pathDefault)
{

    std::vector<YAML::Node> baseNode;
    std::string level;
    std::string casaca;
    std::string formacion;

     if (fileExists(pathIndicado))
         {//loguear levantar path indicado
         baseNode = YAML::LoadAllFromFile(pathIndicado);}
    else{
           if(fileExists(pathDefault))
           {//loguear levantar path deafult
           baseNode = YAML::LoadAllFromFile(pathDefault);
           }
           else{
            //loguear error no hay archivo configuracion disponible disponible TODO: ver como hacer salida elegante
        //LAZAR EXCEPCION
        //exit (-1)
           }
        }


     //obtener debug
    try{
         Debug debugParseado = read_yaml_Debug(baseNode);
         level = debugParseado.get_level();
         if(levelValido(level))
         {//loguar level obtenido
         }
         else{
         //loguear que no se pudo obtener valor level
          throw 0;
         }
        }
    catch(YAML::Exception ex)
    {
    //loguear que no se pudo obtener el nodo Debug
    //intentaro con nodo default
            try{
            std::vector<YAML::Node> baseNodeDefault = YAML::LoadAllFromFile(pathDefault);
            Debug debugParseado = read_yaml_Debug(baseNodeDefault);
            level = debugParseado.get_level();
                    if(levelValido(level))
                    {//loguear level obtenido
                    }
                    else {
                        //lanzar excepcion y loguear que nos se pudo obtener level default
                        throw 0;
                    }
             }
            catch(YAML::Exception ex)
            {
             //loguear que no se pudo obtener el nodo Debug default
             // salir
            }
            catch (int e)
            {
            //loguear que no se pudo obtener el nodo Debug default
             // salir
            }
    }
    catch (int e)
    {
            try{
            std::vector<YAML::Node> baseNodeDefault = YAML::LoadAllFromFile(pathDefault);
            Debug debugParseado = read_yaml_Debug(baseNodeDefault);
            level = debugParseado.get_level();
                    if(levelValido(level))
                    {//loguear level obtenido
                    }
                    else {
                        //lanzar excepcion y loguear que nos se pudo obtener level default
                        throw 0;
                    }
             }
            catch(YAML::Exception ex)
            {
             //loguear que no se pudo obtener el nodo Debug default
             // //exit (-1)
            }
            catch (int)
            {
            //loguear ex
            //exit (-1)
            }
    }







    try{
    Equipo equipoParseado  = read_yaml_Equipo(baseNode);
    casaca = equipoParseado.get_casaca();
      if(casacaValido(casaca))
                    {//loguar casaca obtenido
                    }
                    else{ throw 0;
                    //loguar que no se pudo obtener casaca
                    }
        formacion = equipoParseado.get_formacion();
        if(formacionValido(formacion))
                    {//loguar formacion obtenido
                    }
                    else{ throw 0;
                    //loguear que no se pudo obtener formacion
                    }
    }
    catch(YAML::Exception ex)
    {
//     loguear que no se pudo obtener el nodo
  //  probar con ddbug defualt
        try{
        std::vector<YAML::Node> baseNodeDefault = YAML::LoadAllFromFile(pathDefault);
        baseNodeDefault = YAML::LoadAllFromFile(pathDefault);
        Equipo equipoParseado = read_yaml_Equipo(baseNodeDefault);
        casaca = equipoParseado.get_casaca();
        if(casacaValido(casaca))
                    {//loguar casaca obtenido
                    }
                    else{ throw 0;
                    //loguar que no se pudo obtener casaca default
                    }
                    formacion = equipoParseado.get_formacion();
        if(formacionValido(formacion))
                    {//loguar formacion obtenido
                    }
                    else{ throw 0;
                    //loguear que no se pudo obtener formacion default
                    }
        }
        catch(YAML::Exception ex)
        {
        }
        catch (int e)
            {
            //loguear que no se pudo obtener el nodo Debug default
             // salir
            }
    }
catch(int e)
    {
//     loguear que no se pudo obtener el nodo
  //  probar con ddbug defualt
        try{
        std::vector<YAML::Node> baseNodeDefault = YAML::LoadAllFromFile(pathDefault);
        baseNodeDefault = YAML::LoadAllFromFile(pathDefault);
        Equipo equipoParseado = read_yaml_Equipo(baseNodeDefault);
        casaca = equipoParseado.get_casaca();
        if(casacaValido(casaca))
                    {//loguar casaca obtenido
                    }
                    else{ throw 0;
                    //loguar que no se pudo obtener casaca default
                    }
                    formacion = equipoParseado.get_formacion();
        if(formacionValido(formacion))
                    {//loguar formacion obtenido
                    }
                    else{ throw 0;
                    //loguear que no se pudo obtener formacion default
                    }
        }
        catch(YAML::Exception ex)
        {
        }
        catch (int e)
        {
            //loguear que no se pudo obtener el nodo Debug default
             // salir
        }
    }


Parametros par = Parametros(level,formacion,casaca);
return par;
}

