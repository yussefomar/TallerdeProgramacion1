#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "../Command/Command.h"
#include "../Utils/Observador.h"

#define MSJ 0x00
#define ERR 0x01
#define WAR 0x02
#define MJU 0x03

class Util_LoggerObserver : public Observador
{
    std::string path;
    std::string message;
    int level;
public:
    Util_LoggerObserver(int myLevel);
    virtual ~Util_LoggerObserver();
    int getLoggerLevel();
    std::string getLogFile();
    void writeSingleLine(std::string line, std::string type, std::string mvc);
    void writeMessageLine(std::string message, std::string mvc);
    void writeWarningLine(std::string message, std::string mvc);
    void writeErrorLine(std::string message, std::string mvc);
    void updateLevel(int newLevel);
    void notificar(std::string entidad, char evento, char tipo);

};
