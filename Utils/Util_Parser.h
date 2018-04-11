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

class Util_Parser
{
	public:
		Equipo read_yaml_Equipo(std::string path);
		Debug read_yaml_Debug(std::string path);
};

#endif
