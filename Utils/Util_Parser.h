#ifndef UTIL_PARSER_H_
#define UTIL_PARSER_H_

#include <iostream>
#include <string>
#include <list>
#include <yaml-cpp/yaml.h>

using namespace std;


class Equipo {
public:
	Equipo(const YAML::Node &node) :
		formacion(node["formacion"].as<std::string>()),
		casaca(node["casaca"].as<std::string>()) {};
	std::string const &get_formacion() const { return formacion; };
	std::string const &get_casaca() const { return casaca; };
private:
	std::string formacion;
	std::string casaca;
};

class Debug {
public:
	Debug(const YAML::Node &node) :
		level(node["level"].as<std::string>()) {};
	std::string const &get_level() const { return level; };
private:
	std::string level;
};

struct Parametros
{
    Parametros(){level= ""; formacion=""; casaca =""; }
    Parametros(std::string p_level,std::string p_formacion, std::string p_casaca){
    level= p_level; formacion=p_formacion; casaca =p_casaca; }
    std::string level;
    std::string formacion;
	std::string casaca;
};


class Util_Parser
{
	public:
         inline bool levelValido(std::string &name);
         inline bool casacaValido(std::string &name);
         inline bool formacionValido(std::string &name);
         inline bool fileExists(const std::string& name);

		Equipo read_yaml_Equipo(std::vector<YAML::Node> baseNode);
		Debug read_yaml_Debug(std::vector<YAML::Node> baseNode);
		Parametros read_yaml_Parametros(std::string pathIndicado, std::string pathDefault);

};

#endif
