#include "LogIn.h"
#include "View_Loguin.h"


LogIn::LogIn(ModeloCliente* modelCliente)
{
    char respuesta;
    View_Loguin loguinScreen(1);
    InformacionIngreso informacionIngreso(false);
    loguinScreen.Inicializar();

    while( !informacionIngreso.ipIngresado || !informacionIngreso.puertoIngresado )
    {
        loguinScreen.Procesar(informacionIngreso);
        if(informacionIngreso.ipIngresado && informacionIngreso.puertoIngresado )
        {
            modelCliente->conectarConServer(informacionIngreso.ip, informacionIngreso.puerto);
            informacionIngreso.procesarConectividad(modelCliente->conectadoAlServer());
            //informacionIngreso.procesarConectividad(modelCliente->habilitadoParaJugar()) //aca,el cliente ya puede saber si la partida estaba llena o no.
            //anunciar esto y salir de la partida.
            //===========================================================================
            //informacionIngreso.procesarConectividad(false);
            //===========================================================================
        }
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

    informacionIngreso.mensaje = "A la espera de que todos los jugadores se conecten.";
    loguinScreen.Cerrar();

}

LogIn::~LogIn()
{
    //dtor
}
