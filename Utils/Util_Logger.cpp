#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <list>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

#include "Util_Logger.h"
#include "Util_Common.h"

string logName = "Log.txt";
string logPath =  "./Logs/";

Util_Common util;
unsigned short level;

char const* getLogFile(){
	char const* fullPath = (logPath + logName).c_str();
	return fullPath;
}

void Util_Logger::writeLine(string line)
{
	printf("%s\n",line.c_str());
	if(level >= 3){
		ofstream log_file(getLogFile(), ios_base::out | ios_base::app );
		log_file << util.currentDateTime() + " || " << line << endl;
	    log_file.close();
	}
}

void Util_Logger::writeWarningLine(string line)
{
	if(level >= 2){
		printf("%s\n",line.c_str());
		ofstream log_file(getLogFile(), ios_base::out | ios_base::app );
		log_file << util.currentDateTime() + " || WARNING || " << line << endl;
	    log_file.close();
	}
}

void Util_Logger::writeErrorLine(string line)
{
	if(level >= 1){
		perror((line + "\n").c_str());
		ofstream log_file(getLogFile(), ios_base::out | ios_base::app );
		log_file << util.currentDateTime() + " || ERROR || " << line << endl;
	    log_file.close();
	}
}


void Util_Logger::deleteLine()
{
	// TODO: De momento no tiene un uso determinado.-
}

void Util_Logger::writeBlock(list<string> lineList)
{
    std::ofstream log_file(getLogFile(), std::ios_base::out | std::ios_base::app );
    list<string>::iterator pos;
    pos = lineList.begin();
    while( pos != lineList.end())
    {
    	cout << *pos;
    	log_file << std::endl;
    	log_file << util.currentDateTime() + " || " << *pos << std::endl;
    	pos++;
    }
    log_file.close();
}

void Util_Logger::deleteBlock()
{
	// TODO: De momento no tiene un uso determinado.-
}

// Chequeamos que el archivo exista.
inline bool file_exists (const std::string& name) {
    ifstream f(name.c_str());
    if (f.good()) {
        f.close();
        return true;
    } else {
        f.close();
        return false;
    }
}



void Util_Logger::updateLevel(unsigned short  newLevel)
{
	// Actualizamos el nivel de logueo.
	level = newLevel;
}

void Util_Logger::createFile(unsigned short  newLevel)
{
	// Actualizamos el nivel de logueo.
	level = newLevel;

	// Definimos un nombre para el Log de manera que sea UNIVOCO.-
	string fileDate = "(" + util.currentDateTime() + ") " + logName;
	logName = fileDate.c_str();

	// Creamos e inicializamos nunestro nuevo archivos de log.
	std::ofstream outfile (getLogFile());
	outfile << "Archivo de Log inicializado: " << util.currentDateTime() << std::endl;
	outfile << std::endl;
	outfile.close();

	/** NO ESTA CREANDO EL ARCHIVO CORRECTO, PARA REVIZAR. **/
    /*
	//Chequeamos que haya sido creado exitosamente.
	if(!file_exists(getLogFile())){
		perror(("Missing folder " + logPath).c_str());
		exit(1);
	}*/
}

void Util_Logger::deleteFile()
{
	// TODO: De momento no tiene un uso determinado.-
}
