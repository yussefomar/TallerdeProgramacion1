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

#include "../Utils/Util_LoggerObserver.h"
#include "../Utils/Util_Common.h"


Util_Common utils;

Util_LoggerObserver::Util_LoggerObserver(int myLevel)
{
    this->level = myLevel;

}

Util_LoggerObserver::~Util_LoggerObserver()
{
    //dtor
}

int Util_LoggerObserver::getLoggerLevel()
{
    return this->level;
}

std::string Util_LoggerObserver::getLogFile()
{
    string fullPathString = "./Logs/Log.txt";
    return fullPathString;
}

void Util_LoggerObserver::writeSingleLine(string line, string type, string mvc)
{
    printf("%s", (line + "\n").c_str());
    ofstream log_file(getLogFile(), ios_base::out | ios_base::app );
    log_file << utils.currentDateTime() + " || " + type + " || " + mvc + " || " << line << endl;
    log_file.close();
}

void Util_LoggerObserver::writeMessageLine(std::string line, std::string mvc)
{
    if(getLoggerLevel() >= 3)
    {
        writeSingleLine(line, "MESSAGE", mvc);
    }
}

void Util_LoggerObserver::writeWarningLine(std::string line, std::string mvc)
{
    if(getLoggerLevel() >= 2)
    {
        writeSingleLine(line, "WARNING", mvc);
    }
}

void Util_LoggerObserver::writeErrorLine(std::string line, std::string mvc)
{
    if(getLoggerLevel() >= 1)
    {
        writeSingleLine(line, "ERROR", mvc);
    }
}

void Util_LoggerObserver::updateLevel(int newLevel)
{
    this->level = newLevel;
}


void Util_LoggerObserver::notificar(std::string entidad, char evento, char tipo) {

//    std::string en = std::to_string(entidad);
    if(tipo == MJU)
      {
        this->writeMessageLine("Hubo un cambio en jugador " + entidad, "Se ejecutó: " + evento);
      }
    if(tipo == ERR)
    {
        this->writeErrorLine(entidad, std::to_string(evento));
    }
    if(tipo == WAR)
    {
        this->writeWarningLine(entidad, std::to_string(evento));
    }
    if(tipo == MSJ)
    {
        this->writeMessageLine(entidad, std::to_string(evento));
    }
}
