#pragma once

class IObserver
{
public:
        virtual void writeMessageLine(std::string message, std::string mvc) = 0;
        virtual void writeWarningLine(std::string message, std::string mvc) = 0;
        virtual void writeErrorLine(std::string message, std::string mvc) = 0;
        virtual void updateLevel(int newLevel) = 0;
//        virtual void notificar(char entidad, char evento);
//        virtual void notificarError(char entidad, char evento);
};
