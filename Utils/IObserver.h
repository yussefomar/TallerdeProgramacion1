#pragma once

class IObserver
{
    public:
        virtual void writeMessageLine(std::string message) = 0;
        virtual void writeWarningLine(std::string message) = 0;
        virtual void writeErrorLine(std::string message) = 0;
};
