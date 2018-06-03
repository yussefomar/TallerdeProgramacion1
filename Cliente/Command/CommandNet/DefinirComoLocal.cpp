#include "DefinirComoLocal.h"

DefinirComoLocal::DefinirComoLocal(Model* model) : CommandNet(model)
{
    //ctor
}

DefinirComoLocal::~DefinirComoLocal()
{
    //dtor
}

void DefinirComoLocal::execute()
{
    this->model->definirComoLocal(this->getIdCliente());
}

char DefinirComoLocal::getCodigoComando()
{
    return DEFLOCAL;
}
CommandNet* DefinirComoLocal::getCopia() {
    return new DefinirComoLocal(this->model);
}
