#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "IObserver.h"

class Util_LoggerObserver : IObserver
{
        std::string path;
        std::string message;
        int level;
    public:
        Util_LoggerObserver(int myLevel);
        int getLoggerLevel();
        std::string getLogFile();

        void writeSingleLine(std::string line, std::string type);

        void writeMessageLine(std::string line);
        void writeWarningLine(std::string line);
        void writeErrorLine(std::string line);
};
