#include "VerificarInformacion.h"

VerificarInformacion::VerificarInformacion(Cliente* cliente, ModeloServidor* modeloServidor) :
    cliente(cliente), modelo(modeloServidor)
{
    //ctor
}

VerificarInformacion::~VerificarInformacion()
{
    //dtor
}

void VerificarInformacion::procesoAEjecutar()
{
    bool sinUsuario = true;
    bool sinPass = true;
    char usuario;
    char password;

    while(sinUsuario)
    {
        usuario = this->cliente->recibirUsuario();
        sinUsuario = this->modelo->verificarUsuario(usuario, this->cliente->getID());
    }

    while(sinPass)
    {
        password = this->cliente->recibirPassword();
        sinPass = this->modelo->verificarPassword(usuario, password, this->cliente->getID());
    }
}
