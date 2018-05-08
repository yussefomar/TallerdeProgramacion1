#ifndef COMMANDNET_H
#define COMMANDNET_H

#include <Command.h>
#include <map>


class CommandNet : public Command
{
    public:
        CommandNet();
        virtual ~CommandNet();
        void setCodigoComando(char codigoComando);

        void setearCodigoJugador(char codigoJugador);
       /* char getCodigoComando();
    void execute();*/
    protected:
     char codigoJugador;
    private:
        char codigoComando;

};

#endif // COMMANDNET_H
