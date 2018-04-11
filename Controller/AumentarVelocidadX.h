#ifndef AUMENTARVELOCIDADX_H
#define AUMENTARVELOCIDADX_H

#include <Command.h>
#include "Model.h"


class AumentarVelocidadX : public Command
{
    public:
        AumentarVelocidadX();
        virtual ~AumentarVelocidadX();
        void execute();
        void setModel(Model& model);

    protected:

    private:
        Model model;
};

#endif // AUMENTARVELOCIDADX_H
