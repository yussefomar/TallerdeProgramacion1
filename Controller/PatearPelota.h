#ifndef PATEARPELOTA_H
#define PATEARPELOTA_H
#include "../Controller/Command.h"
#include "../Model/Model.h"
#include "iostream"

class PatearPelota : public Command
{
    public:
        PatearPelota(Model* model);
        virtual ~PatearPelota();
        void execute();
         char getCodigoComando();

    protected:

    private:
        Model* model;
};

#endif // PATEARPELOTA_H
