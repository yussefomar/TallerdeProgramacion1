#include "../Utils/Util_Subject.h"
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void Util_Subject::Attach(Command* command)
{
   oyentes.push_back(command);

}
void Util_Subject::Detach(Command* command)
{
   oyentes.erase(std::remove(oyentes.begin(), oyentes.end(), command), oyentes.end());
}


void Util_Subject::Notify(unsigned int jugadorActivo, char codigo)
{

    for(vector<Command*>::const_iterator iter = oyentes.begin(); iter != oyentes.end(); ++iter)
    {
        if(*iter != 0)
        {
        char aa = (*iter)->getCodigoComando();
            if(aa ==  codigo) //chekear que entre en el codigo al llamar al notivy
            {(*iter)->execute();}
        }
    }
}
