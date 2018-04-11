#ifndef AUMENTARVELOCIDADY_H
#define AUMENTARVELOCIDADY_H

#include <Command.h>
#include "Model.h"


class AumentarVelocidadY : public Command
{
    public:
        AumentarVelocidadY();
        virtual ~AumentarVelocidadY();
        void execute();
        void setModel(Model& model);


    protected:

    private:
        Model model;
};

#endif // AUMENTARVELOCIDADY_H
