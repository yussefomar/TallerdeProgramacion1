#ifndef DESCONEXIONAJENA_H
#define DESCONEXIONAJENA_H

#include <CommandNet.h>


class DesconexionAjena : public CommandNet
{
    public:
        DesconexionAjena(Model* model);
        virtual ~DesconexionAjena();
            void  execute() ;
    char  getCodigoComando() ;
    CommandNet* getCopia();

    protected:

    private:
};

#endif // DESCONEXIONAJENA_H
