#include "../Controller/DisminuirVelocidadX.h"
#include "../Model/Model_Jugador.h"

DisminuirVelocidadX::DisminuirVelocidadX(Model* model)
{
    this->model = model;
}

DisminuirVelocidadX::~DisminuirVelocidadX()
{
    //dtor
}

void DisminuirVelocidadX::execute()
{
    this->model->jugadorActivoDisminuyeVelocidadEnX();
}

char DisminuirVelocidadX::getCodigoComando()
{
    return DECVELX;
}
