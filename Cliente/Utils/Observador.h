#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

class Observador
{
    public:
        virtual void notificar(std::string entidad, char evento, char tipo) = 0;

};
