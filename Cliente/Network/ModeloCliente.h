#ifndef MODELOCLIENTE_H
#define MODELOCLIENTE_H
#include <Model.h>

#include "../Command/CommandNet.h"
#include "SocketCliente.h"

class ModeloCliente : public Model
{
public:
    ModeloCliente(Model* model);
    virtual ~ModeloCliente();

    /*Datos del Modelo*/
    virtual Pelota* getPelota();
    virtual Jugador* getJugadorNro(int i);
    virtual Jugador* getJugadorActivo();
    virtual std::string  getCasaca();
    virtual void setCamara(SDL_Rect * camara);
    virtual void setFormacion(Formacion* formacion);
    virtual void setCasaca(std::string casacaName);

    /*Servicios del Modelo*/
    virtual void agregarCambio(Command* cambio);
    virtual void jugadorActivoAumentaVelocidadEnX();
    virtual void jugadorActivoAumentaVelocidadEnY();
    virtual void jugadorActivoDisminuyeVelocidadEnX();
    virtual void jugadorActivoDisminuyeVelocidadEnY();
    virtual void jugadorActivoAcelera();
    virtual void jugadorActivoDesacelera();
    virtual void jugadorActivoPateaPelota();
    virtual void jugadorActivoRecuperaPelota();
    virtual void jugadorActivoDetener();
    virtual void cambiarJugadorActivo();
    virtual void update();

    void enviarUnComando();
    void recibirUnComando();
    void ejecutarUnComando();

    void conectarConServer(std::string ipServer, std::string puertoServer);
    void setComoLocal();
    void setComoVisitante();
    bool conectadoAlServer();

    void enviarNombre(std::string nombre);
    void enviarPassword(std::string password);
    void enviarNombrePassword(std::string nombre, std::string password);
    char recibirValidacionNombre();
    char recibirValidacionPassword();
    char hashear(std::string unString);

    void consultarInicio();
    void recibirRespuestaInicio();
    bool habilitadoParaJugar();
    void intentarReconexion();
    void actualizar();
    void tomarUnJugadorLibre();

    void tratarDesconexion();

    void enviarBackup();
    void recibirBackup();




protected:

private:
    Model* model;
    std::vector<CommandNet*> comandos;
    std::queue<char> codigosAEnviar;
    SocketCliente* socket;
    unsigned tareaAEjecutar;
    char idCliente;
    char nombre;
    char password;
    char credencial;
    std::string ip;
    std::string puerto;
    char lugarEnCancha;
};

#endif // MODELOCLIENTE_H
