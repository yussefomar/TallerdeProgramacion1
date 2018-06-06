#ifndef COMMAND_H
#define COMMAND_H

/*Los codigos de los comandos deberian figurar aqui.*/
/*Los codigos de los comandos deberian figurar aqui.*/

/*Los codigos deberian ser los mismos para controller
como para net*/
#define DECVELX 0x00
#define DECVELY 0x01
#define INCVELX 0x02
#define INCVELY 0x03
#define STOPJUG 0x04
#define ACCJUG 0x05
#define DESJUG 0x06
#define PATPELO 0x07
#define RECUPELO 0x08
#define CAMBJUG 0x09
#define COMMNULL 0x0A
#define PASPELO 0x0B
#define DEFLOCAL 0x0C
#define DEFVISIT 0x0D //cuidado con estos dos ultimos comandos.
#define DESCJUG 0x0E
#define NECRENDER 0X0F
#define ARMARBACKUP 0x10

#define CANTCOMMANDS 17

class Command
{
public:
    Command();
    virtual ~Command();
    virtual void execute() = 0;
    virtual char getCodigoComando()=0;

protected:

private:
};

#endif // COMMAND_H
