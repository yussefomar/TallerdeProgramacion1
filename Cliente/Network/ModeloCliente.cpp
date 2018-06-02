#include "ModeloCliente.h"
#include "DisminuirVelocidadYNet.h"
#include "AumentarVelocidadYNet.h"
#include "DisminuirVelocidadXNet.h"
#include "AumentarVelocidadXNet.h"
#include "CambiarJugadorNet.h"
#include "StopJugadorNet.h"
#include "AcelerarNet.h"
#include "DesacelerarNet.h"
#include "PatearPelotaNet.h"
#include "PasarPelotaNet.h"
#include "RecuperarPelotaNet.h"
#include "CommandNullNet.h"
#include "DefinirComoVisit.h"
#include "DefinirComoLocal.h"
#include "DesconexionAjena.h"
#include "RenderizarModel.h"

#include <unistd.h>


#define ENVIAR 0
#define RECIBIR 1
#define EJECUTAR 2

#define LI_CONSULTO_INICIO 0X11
#define LI_INICIO_OK 0X12

/*Cuidado... la cantidad de comandos en modelCliente puede y
va a diferir del de controller*/
ModeloCliente::ModeloCliente(Model* model)
{
    this->model = model;
    this->comandos = std::vector<CommandNet*>(CANTCOMMANDS);
    this->comandos[DECVELX] = new DisminuirVelocidadXNet(model);
    this->comandos[DECVELY] = new DisminuirVelocidadYNet(model);
    this->comandos[INCVELX] = new AumentarVelocidadXNet(model);
    this->comandos[INCVELY] = new AumentarVelocidadYNet(model);
    this->comandos[STOPJUG] = new StopJugadorNet(model);
    this->comandos[ACCJUG] = new AcelerarNet(model);
    this->comandos[DESJUG] = new DesacelerarNet(model);
    this->comandos[PATPELO] = new PatearPelotaNet(model);
    this->comandos[RECUPELO] = new RecuperarPelotaNet(model);
    this->comandos[CAMBJUG] = new CambiarJugadorNet(model);
    this->comandos[PASPELO] = new PasarPelotaNet(model);  //pasar pelota aun no esta creado en net
    this->comandos[COMMNULL]  = new CommandNullNet(model);
    this->comandos[DEFLOCAL] = new DefinirComoLocal(model);
    this->comandos[DEFVISIT] = new DefinirComoVisit(model);
    this->comandos[DESCJUG] = new DesconexionAjena(model);
    this->comandos[NECRENDER] = new RenderizarModel(model);
    this->tareaAEjecutar = 0;

    this->socket = nullptr;
}

ModeloCliente::~ModeloCliente()
{
    for(unsigned i = 0; i < CANTCOMMANDS; ++i)
    {
        delete this->comandos[i];
    }
    if(this->socket != nullptr)
    {
        delete this->socket;

    }
}

void ModeloCliente::conectarConServer(std::string ipServer, std::string puertoServer)
{
    this->ip = ipServer;
    this->puerto = puertoServer;
    this->socket = new SocketCliente(ipServer, puertoServer);
    this->idCliente = this->socket->recibirByte();
    this->model->setIdCliente(this->idCliente);
    this->model->setTodosJugadoresInactivos();
    std::cout << "El cliente se identifica " << this->model->getIdCliente() << std::endl;
}

/*El modelo cliente puede devolver datos que son necesarios*/

Pelota* ModeloCliente::getPelota()
{
    return this->model->getPelota();
}

Jugador* ModeloCliente::getJugadorNro(int i)
{
    return this->model->getJugadorNro(i);
}

Jugador* ModeloCliente::getJugadorActivo()
{
    return this->model->getJugadorActivo();
}

std::string ModeloCliente::getCasaca()
{
    return this->model->getCasaca();
}

/*El modelo cliente no deberia modificar al modelo*/

void ModeloCliente::setCamara(SDL_Rect* camara)
{
    return;
}

void ModeloCliente::setFormacion(Formacion* formacion)
{
    return;
}

void ModeloCliente::setCasaca(std::string casacaName)
{
    return;
}

void ModeloCliente::jugadorActivoAumentaVelocidadEnX()
{
    return;
}
void ModeloCliente::jugadorActivoAumentaVelocidadEnY()
{
    return;
}
void ModeloCliente::jugadorActivoDisminuyeVelocidadEnX()
{
    return;
}
void ModeloCliente::jugadorActivoDisminuyeVelocidadEnY()
{
    return;
}
void ModeloCliente::jugadorActivoAcelera()
{
    return;
}
void ModeloCliente::jugadorActivoDesacelera()
{
    return;
}
void ModeloCliente::jugadorActivoPateaPelota()
{
    return;
}
void ModeloCliente::jugadorActivoRecuperaPelota()
{
    return;
}
void ModeloCliente::jugadorActivoDetener()
{
    return;
}
void ModeloCliente::cambiarJugadorActivo()
{
    return;
}



/*El modelo cliente tiene toda la responsabilidad sobre conexiones via red.*/





void ModeloCliente::update()
{
    if(!this->conectadoAlServer())
    {
        this->intentarReconexion();
    }
    this->tareaAEjecutar = this->tareaAEjecutar % 3;
    if(this->tareaAEjecutar == ENVIAR)
    {
        this->enviarUnComando();
        this->model->moverJuego();
    }
    else if (this->tareaAEjecutar == RECIBIR)
    {
        this->recibirUnComando();
        this->model->moverJuego();
    }
    else if (this->tareaAEjecutar == EJECUTAR)
    {
        this->ejecutarUnComando();
    }
    this->tareaAEjecutar += 1;
}



void ModeloCliente::agregarCambio(Command* cambio)
{
    if(cambio->getCodigoComando() == COMMNULL)
        return;
    char evento = cambio->getCodigoComando();
    char entidad = this->model->getIdCliente();
    entidad = entidad << 6;
    char codigo = entidad | evento;
    this->codigosAEnviar.push(codigo);
}


void ModeloCliente::enviarUnComando()
{
    if(this->codigosAEnviar.empty())
    {
        this->socket->enviarByte(COMMNULL);
        return;
    }

    char codigo = this->codigosAEnviar.front();
    this->codigosAEnviar.pop();
    this->socket->enviarByte(codigo);
}

void ModeloCliente::recibirUnComando()
{
    char codigo = this->socket->recibirByte();
    char entidad = codigo >> 6;
    char evento = 0x3F & codigo;
    CommandNet* comando = this->comandos[evento];
    comando->setIdCliente(entidad);
    this->model->agregarCambio(comando);
}

void ModeloCliente::ejecutarUnComando()
{
    this->model->update();
}

void ModeloCliente::setComoLocal()
{
    char entidad = this->model->getIdCliente();
    entidad = entidad << 6;
    char codigo = DEFLOCAL | entidad;
    this->lugarEnCancha = codigo;
    this->codigosAEnviar.push(codigo);
    this->lugarEnCancha = '1';
}

void ModeloCliente::setComoVisitante()
{
    char entidad = this->model->getIdCliente();
    entidad = entidad << 6;
    char codigo = DEFVISIT | entidad;
    this->lugarEnCancha = codigo;
    this->codigosAEnviar.push(codigo);
    this->lugarEnCancha = '2';
}

bool ModeloCliente::conectadoAlServer()
{
    return this->socket->estaConectado();
}

char ModeloCliente::hashear(std::string unString)
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

void ModeloCliente::enviarNombre(std::string nombre)
{
    char nombreComprimido = this->hashear(nombre);
    this->nombre = nombreComprimido;
    this->socket->enviarByte(nombreComprimido);
}

void ModeloCliente::enviarPassword(std::string password)
{
    char passwordComprimido = this->hashear(password);
    this->password = passwordComprimido;
    this->socket->enviarByte(passwordComprimido);
}

void ModeloCliente::enviarNombrePassword(std::string nombre, std::string password)
{
    std::string credencial = nombre + password;
    char credencialComprimido = this->hashear(credencial);
    this->credencial = credencialComprimido;
    this->socket->enviarByte(credencialComprimido);
}

char ModeloCliente::recibirValidacionNombre()
{
    return this->socket->recibirByte();
}

char ModeloCliente::recibirValidacionPassword()
{
    return this->socket->recibirByte();
}

void ModeloCliente::consultarInicio()
{
    this->socket->enviarByte(LI_CONSULTO_INICIO);
}

void ModeloCliente::recibirRespuestaInicio()
{
    char respuesta = this->socket->recibirByte(); // con esto determinamos si es un rechazado o un aceptado...
    if(respuesta != LI_INICIO_OK) {

        this->idCliente = 5;
    }

}

bool ModeloCliente::habilitadoParaJugar()
{
    unsigned nroId = this->idCliente;

    return nroId > 4; //los rechazados siempre tienen un valor mayor a 5;
}

void ModeloCliente::intentarReconexion()
{
    this->model->desconectarCliente(this->idCliente);
    while(!this->socket->estaConectado())
    {
        this->socket->reconectar(this->ip, this->puerto);
        usleep(1000);
    }
    std::cout << "se conecto" << std::endl;
    //Proceso de verificacion de identidad
    this->socket->enviarByte(this->nombre);
    this->idCliente = this->socket->recibirByte();
    this->socket->enviarByte(this->password);
    this->idCliente = this->socket->recibirByte();
    //en lugar de enviar una validacion se envia el id del cliente que no deberia cambiar.
    this->idCliente = this->socket->recibirByte();
    //this->actualizar();
    if(this->lugarEnCancha == '1') {
        this->setComoLocal();
    } else {
        this->setComoVisitante();
    }

}

