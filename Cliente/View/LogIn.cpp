#include "LogIn.h"
#include "View_Loguin.h"
#include <unistd.h>

Util_datosGuardados dg;

LogIn::LogIn(ModeloCliente* modelCliente)
{
    char respuesta;
    View_Loguin loguinScreen(1);
    InformacionIngreso informacionIngreso(false);
    loguinScreen.Inicializar();

    DatosConexion datosConexion = dg.getDatosConexion();
    informacionIngreso.ip = datosConexion.ip;
    informacionIngreso.puerto = datosConexion.puerto;

    if(!informacionIngreso.ip.empty())
        informacionIngreso.ipIngresado = true;

    while( !informacionIngreso.ipIngresado || !informacionIngreso.puertoIngresado )
    {

        loguinScreen.Procesar(informacionIngreso);
        if(informacionIngreso.ipIngresado && informacionIngreso.puertoIngresado )
        {
            modelCliente->conectarConServer(informacionIngreso.ip, informacionIngreso.puerto);
            informacionIngreso.procesarConectividad(modelCliente->conectadoAlServer());
        }
    }
    dg.setDatosConexionFile(informacionIngreso.puerto,informacionIngreso.ip);

    unsigned int microseconds = 7000;
    //SI MI INGRESO ES CORRECTO ME FIJO SI PUEDO ENTRAR A JUGAR.
    if(!modelCliente->habilitadoParaJugar())
    {
        //EN ESTE CASO MUESTRO UN CARTEL PARA LUEGO SALIR.
        informacionIngreso.mensaje = "El cupo de jugadores se encuentra al tope.";
        loguinScreen.Procesar(informacionIngreso);
        this->puedeArrancar = false;
        usleep(microseconds);
        return;
    }

    std::cout << "llegamos a la ip, vamos por el nombre" << std::endl;
    while( !informacionIngreso.nombreIngresado )
    {
        loguinScreen.Procesar(informacionIngreso);
        if(informacionIngreso.nombreIngresado)
        {
            //modelCliente->enviarNombre(informacionIngreso.nombre);
            //respuesta = modelCliente->recibirValidacionNombre();
            //informacionIngreso.procesarRespuesta(respuesta);
            std::cout << "entramos en if del nombre" << std::endl;

            //===========================================================================
            //informacionIngreso.procesarRespuesta(0X0B);
            //===========================================================================
        }
    }
    std::cout << "llegamos al nombre, vamos por pass" << std::endl;

    while( !informacionIngreso.passwordIngresado )
    {
        loguinScreen.Procesar(informacionIngreso);
        if(informacionIngreso.passwordIngresado)
        {
            modelCliente->enviarNombrePassword(informacionIngreso.nombre, informacionIngreso.password);
            respuesta = modelCliente->recibirValidacionPassword();
            informacionIngreso.procesarRespuesta(respuesta);
            std::cout << "entramos en if del pass" << std::endl;

            //===========================================================================
            //informacionIngreso.procesarRespuesta(0X0F);
            //===========================================================================
        }
    }
    std::cout << "llegamos al pass, vamos por equipo" << std::endl;

    while( !informacionIngreso.equipoIngresado )
    {
        loguinScreen.Procesar(informacionIngreso);
        if(informacionIngreso.equipoIngresado)
        {
            if(informacionIngreso.equipo == "1")
            {
                modelCliente->setComoLocal();
            }
            else if(informacionIngreso.equipo == "2")
            {
                modelCliente->setComoVisitante();
            }
            else
            {
                informacionIngreso.equipoErroneo();
            }
        }
    }

    //EN CASO DE QUE HAYA LUGAR PARA JUGAR ESPERO A QUE TODOS SE ENCUENTREN LISTOS.
//    informacionIngreso.mensaje = "A la espera de que todos los jugadores se conecten.";
//    loguinScreen.Procesar(informacionIngreso);
    this->puedeArrancar = true;
    loguinScreen.Cerrar();

}

LogIn::~LogIn()
{
    //dtor
}
