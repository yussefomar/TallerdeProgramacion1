#ifndef COMMAND_H
#define COMMAND_H

/*Los codigos de los comandos deberian figurar aqui.*/
/*Los codigos de los comandos deberian figurar aqui.*/
#define NDECVELX 0x01
#define NDECVELY 0x02
#define NINCVELX 0x03
#define NINCVELY 0x04
#define NSTOPJUG 0x05
#define NACCJUG 0x06
#define NDESJUG 0x07
#define NPATPELO 0x08
#define NRECUPELO 0x09
#define NCAMBJUG 0x0A

class Command
{
public:
    Command();
    virtual ~Command();
    virtual void execute() = 0;
    //Despues agregar el = 0 para asegurarse de que todo
    //todo comando tenga un codigo apropiado
    virtual char getCodigoComando()=0;;

protected:

private:
};

#endif // COMMAND_H
