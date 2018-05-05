#ifndef COMMAND_H
#define COMMAND_H

/*Los codigos de los comandos deberian figurar aqui.*/
class Command
{
public:
    Command();
    virtual ~Command();
    virtual void execute() = 0;
    //Despues agregar el = 0 para asegurarse de que todo
    //todo comando tenga un codigo apropiado
    virtual char getCodigoComando();

protected:

private:
};

#endif // COMMAND_H
