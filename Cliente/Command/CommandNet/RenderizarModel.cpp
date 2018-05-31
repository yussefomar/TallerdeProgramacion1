#include "RenderizarModel.h"

RenderizarModel::RenderizarModel(Model* model) : CommandNet(model)
{
    //ctor
}

RenderizarModel::~RenderizarModel()
{
    //dtor
}

char RenderizarModel::getCodigoComando() {
    return NECRENDER;
}

void RenderizarModel::execute() {
    this->model->habilitarRender();
}
