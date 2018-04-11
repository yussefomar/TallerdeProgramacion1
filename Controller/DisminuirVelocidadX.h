#ifndef DISMINUIRVELOCIDADX_H
#define DISMINUIRVELOCIDADX_H

#include <Command.h>
#include "Model.h"


class DisminuirVelocidadX : public Command
{
    public:
        DisminuirVelocidadX();
        virtual ~DisminuirVelocidadX();
        void execute();
        void setModel(Model& model);

    protected:

    private:
        Model model;
};

#endif // DISMINUIRVELOCIDADX_H
