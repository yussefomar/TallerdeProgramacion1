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


std::string transformarEvento(char evento);

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


void Util_LoggerObserver::notificar(std::string entidad, char evento, char tipo)
{
    if(tipo == MJU)
    {
        this->writeMessageLine("Se ejecutó: " + transformarEvento(evento), "Hubo un cambio en jugador " + entidad);
    }
    if(tipo == ERR)
    {
        this->writeErrorLine("Error: " + transformarEvento(evento), entidad);
    }
    if(tipo == WAR)
    {
        this->writeWarningLine("Warning: " + transformarEvento(evento), entidad);
    }
    if(tipo == MSJ)
    {
        this->writeMessageLine("Mensaje: " + transformarEvento(evento), entidad);
    }
}

std::string transformarEvento(char evento)
{
    if(evento == DECVELX)
        return "DisminuirVelocidadXNet";
    if(evento == DECVELY)
        return "DisminuirVelocidadYNet";
    if(evento == INCVELX)
        return "AumentarVelocidadXNet";
    if(evento == INCVELY)
        return "AumentarVelocidadYNet";
    if(evento == CAMBJUG)
        return "CambiarJugadorNet";
    if(evento == STOPJUG)
        return "StopJugadorNet";
    if(evento == ACCJUG)
        return "AcelerarNet";
    if(evento == DESJUG)
        return "DesacelerarNet";
    if(evento == PATPELO)
        return "PatearPelotaNet";
    if(evento == RECUPELO)
        return "RecuperarPelotaNet";
    if(evento == COMMNULL)
        return "CommandNullNet";
    if(evento == DEFLOCAL)
        return "DefinirLocalNet";
    if(evento == DEFVISIT)
        return "DefinirVisitanteNet";
    return std::to_string(evento);
}
