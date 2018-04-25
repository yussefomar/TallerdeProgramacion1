#ifndef ACELERAR_H
#define ACELERAR_H

#include "../Controller/Command.h"
#include "../Model/Model.h"


class Acelerar : public Command
{
public:
    Acelerar(Model* model);
    virtual ~Acelerar();
    void execute();


protected:

private:
    Model* model;
};

#endif // ACELERAR_H
