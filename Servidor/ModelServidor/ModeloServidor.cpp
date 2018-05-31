#include "ModeloServidor.h"
#include "VerificarInformacion.h"


#define LI_NOMBRE_OK 0X0B //NOMBRE CORRECTO.
#define LI_NOMBRE_ERROR 0X0C //NOMBRE INCORRECTO.
#define LI_NOMBRE_REPETIDO 0X0D //NOMBRE EXISTENTE.
#define LI_CREDENCIALES_OK 0X0E //CREDENCIALES CORRECTAS.
#define LI_CREDENCIALES_ERROR 0X0F //CREDENCIALES INCORRECTAS.
#define LI_CONSULTO_INICIO 0X11 //ME PREGUNTAN SI SE INICIO.
#define LI_INICIO_OK 0X12 //RESPONDO QUE ESTAN TODOS CONECTADOS.

ModeloServidor::ModeloServidor()
{

}

ModeloServidor::~ModeloServidor()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        delete this->clientes[i];
    }
    delete this->buffer;
    delete this->tratarClientes;
}

void ModeloServidor::aceptarClientesEntrantes()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i] = new Cliente(this->buffer, this->ip, this->puerto);
        this->clientes[i]->enviarId(i);
    }
}

void ModeloServidor::tratarNuevosClientes()
{
    this->tratarClientes->setIpPuerto(this->ip, this->puerto);
    this->tratarClientes->empezarNuevoHilo();
}

void ModeloServidor::enviarMensajes()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i]->enviarMensaje();
    }
    return;
}

void ModeloServidor::recibirMensajes()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i]->recibirMensaje();
    }
    return;
}

bool ModeloServidor::clientesEstanConectados()
{
    bool estanConectados = false;

    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        estanConectados |= this->clientes[i]->estaConectado();
    }
    return estanConectados;
}


bool ModeloServidor::hayCambiosPorEnviar()
{
    bool hayCambios = false;

    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        hayCambios |= this->clientes[i]->hayCambios();
    }
    return hayCambios;
}

void ModeloServidor::recibirInformacion()
{
    //Se lanza un hilo por cada cliente.
    std::vector<VerificarInformacion*> verificadores = std::vector<VerificarInformacion*>(this->clientes.size());
    for(unsigned i = 0; i < this->clientes.size(); ++i) {
        verificadores[i] = new VerificarInformacion(this->clientes[i], this);
        verificadores[i]->empezarNuevoHilo();
    }

    for(unsigned i = 0; i < this->clientes.size(); ++i) {
        verificadores[i]->bloquearHiloInvocante();
        delete verificadores[i];
    }
    return;
}

void ModeloServidor::enviarOKInicio()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i]->enviarRespuesta(LI_INICIO_OK);
    }
    return;
}

bool ModeloServidor::verificarUsuario(char usuario, unsigned i)
{
    for(unsigned j = 0; j < this->clientes.size(); ++j)
    {
        //Para todos menos para el usuario actual.
        if(i != j)
        {
            //Si hay otro usuario con el mismo nombre está mal.
            if(this->clientes[j]->nombreUsuario == usuario)
            {
                //0X0D NOMBRE OCUPADO.
                this->clientes[i]->enviarRespuesta(0X0D);
                return true;
            }
        }
    }
    for(unsigned j = 0; j < this->usuariosNombre.size(); ++j)
    {
        if(this->usuariosNombre[j] == usuario)
        {
            //0X0B NOMBRE CORRECTO Y LIBRE. //ACTUALIZO EL CLIENTE.
            this->clientes[i]->nombreUsuario = usuario;
            this->clientes[i]->enviarRespuesta(0X0B);
            return false;
        }
    }
    // 0X0C NOMBRE INCORRECTO.
    this->clientes[i]->enviarRespuesta(0X0C);
    return true;
}

bool ModeloServidor::verificarPassword(char usuario, char password, unsigned i)
{
    //EL INDICE DEL USUARIO Y EL PASSWORD POR LÓGICA DEBEN DE COINCIDIR.-
    for(unsigned j = 0; j < this->usuariosNombre.size(); ++j)
    {
        if(this->usuariosNombre[j] == usuario && this->usuariosPassword[j] == password)
        {
            //0X0E NOMBRE CORRECTO Y CONTRASEÑA CORRECTA.
            this->clientes[i]->enviarRespuesta(0X0E);
            return false;
        }
    }
    // 0X0F CREDENCIALES CORRECTAS. //ACTUALIZO EL CLIENTE.
    this->clientes[i]->nombreUsuario = usuario;
    this->clientes[i]->passwordUsuario = password;
    this->clientes[i]->enviarRespuesta(0X0F);
    return true;
}

char ModeloServidor::hashear(std::string unString)
{
    char code = 0X00;
    char caracter = 0X00;

    int hasha = 7;
    for(unsigned i = 0; i < unString.size(); ++i)
    {
        caracter = unString[i];
        hasha = hasha*31 + caracter;
    }
    code = hasha;
    return code;
}

void ModeloServidor::setClientesPermitidos(unsigned cantidadMaxClientes)
{
    this->clientes = (std::vector<Cliente*>(cantidadMaxClientes));
    this->buffer = new Buffer(cantidadMaxClientes);
    this->tratarClientes = new TratarClientesNuevos(cantidadMaxClientes);
    for(unsigned i = 0; i < cantidadMaxClientes; ++i) {
        this->tratarClientes->agregarCliente(this->clientes[i], i);
    }
}

void ModeloServidor::setIpYPuerto(std::string ip, std::string puerto)
{
    this->ip = ip;
    this->puerto = puerto;
}
