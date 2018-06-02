#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <list>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

#include "../Utils/Util_datosGuardados.h"

const std::string path = "./Logs/datos.txt";

bool Util_datosGuardados::fileExist(const std::string& name)
{
    try
    {
        ifstream f(name.c_str());

        if (f.good())
        {
            f.seekg(0, ios::end); // va al final de archivo
            if(f.tellg()==0)
            {
                f.close();
                return false;
            }
            else
            {
                f.close();
                return true;
            }
        }
        else
        {
            f.close();
            return false;
        }
    }
    catch(...)
    {
        return false;
    }
}

void Util_datosGuardados::writeSingleLine(string line)
{
    printf("%s", (line + "\n").c_str());
    ofstream datosFile(path, ios_base::out | ios_base::app );
    datosFile << line << endl;
    datosFile.close();
}

void Util_datosGuardados::setDatosConexionFile(std::string p_puerto, std::string p_ip)
{
std::ofstream outfile (path);
//outfile.open(getLogFile());
writeSingleLine(p_ip);
writeSingleLine(p_puerto);
}

DatosConexion Util_datosGuardados::getDatosConexion()
{
    if(fileExist(path))
    {
        //leer de archivo
        ifstream archivo(path);;
        std::string ip = "";
        std::string puerto ="" ;
        std::string str;
        unsigned i = 0;
        while (std::getline(archivo, str))
        {
            if( i == 1)
            {puerto = str;}
            else
            {ip = str;}
            i++;
        }
       archivo.close();

       DatosConexion datosConexion(puerto, ip);
       return datosConexion;
    }
    else
    {
     DatosConexion datosConexion;
     return datosConexion;
    }
}




