#include "DefinirComoVisit.h"

DefinirComoVisit::DefinirComoVisit(Model* model) : CommandNet(model)
{
    //ctor
}

DefinirComoVisit::~DefinirComoVisit()
{
    //dtor
}

void DefinirComoVisit::execute()
{
    this->model->definirComoVisitante(this->getIdCliente());
}

char DefinirComoVisit::getCodigoComando()
{
    return DEFVISIT;
}

CommandNet* DefinirComoVisit::getCopia() {
    return new DefinirComoVisit(this->model);
}
