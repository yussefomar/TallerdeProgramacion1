#ifndef DESACELERAR_H
#define DESACELERAR_H

#include "../Controller/Command.h"
#include "../Model/Model.h"

class Desacelerar : public Command
{
    public:
        Desacelerar(Model* model);
        virtual ~Desacelerar();
            void execute();


    protected:

    private:
        Model* model;
};

#endif // DESACELERAR_H
