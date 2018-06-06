#include "ArmarBackup.h"

ArmarBackup::ArmarBackup(Model* model) : CommandNet(model)
{
    //ctor
}

ArmarBackup::~ArmarBackup()
{
    //dtor
}

void ArmarBackup::execute() {
    this->model->comenzarAArmarBackup();
}

char ArmarBackup::getCodigoComando() {
    return ARMARBACKUP;
}

CommandNet* ArmarBackup::getCopia() {
    return new ArmarBackup(this->model);
}

