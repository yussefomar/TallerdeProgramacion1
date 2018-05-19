#pragma once
#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include "../Command/Command.h"

class Util_Subject 
{
    std::vector<Command*> oyentes;


public:
    void Attach(Command* command);
    void Detach(Command* command);

    //comentar
     void Notify(unsigned int jugadorActivo, char codigo);
};


