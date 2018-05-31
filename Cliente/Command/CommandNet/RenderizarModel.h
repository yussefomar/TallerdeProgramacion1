#ifndef RENDERIZARMODEL_H
#define RENDERIZARMODEL_H

#include <CommandNet.h>


class RenderizarModel : public CommandNet
{
    public:
        RenderizarModel(Model* model);
        virtual ~RenderizarModel();
            void  execute() ;
    char  getCodigoComando() ;


    protected:

    private:
};

#endif // RENDERIZARMODEL_H
