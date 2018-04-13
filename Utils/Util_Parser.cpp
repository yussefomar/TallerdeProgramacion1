#include <yaml-cpp/yaml.h>

using namespace std;

#include "Util_Parser.h"

std::vector<Equipo> equipos;
std::vector<Debug> debugs;

Equipo Util_Parser::read_yaml_Equipo(std::string path)
{
	std::vector<YAML::Node> baseNode = YAML::LoadAllFromFile(path);

	for (auto &document : baseNode)
    {
        equipos.emplace_back(document["equipo"]);
    }
    return equipos.at(0);
}

Debug Util_Parser::read_yaml_Debug(std::string path)
{
	std::vector<YAML::Node> baseNode = YAML::LoadAllFromFile(path);

	for (auto &document : baseNode)
    {
        debugs.emplace_back(document["debug"]);
    }
    return debugs.at(0);
}
