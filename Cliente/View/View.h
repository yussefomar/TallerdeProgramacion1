#ifndef VIEW_H
#define VIEW_H

#include "../View/ViewModel.h"
#include "../Model/Model.h"
#include "../Model/Model_Jugador.h"
#include "../View/View_Mensajes.h"
#include "../Utils/Observador.h"
#include <string>

#define ERR_CON 0x20
#define ERR_ESP 0x21
#define OK_CONTINUA 0x22

class View : public Util_LoggerSubject, public Observador
{
public:
    View(Model* model);
    virtual ~View();
    void ajustarCamara();
    void mostrarCartel();
    void cargarCartel(std::string mensaje);
    void limpiarCartel();
    void render();
    bool inicializar();
    void loadMedia();
    void close();
    void notificar(std::string entidad, char evento, char tipo);

private:
    Model* model;
    Jugador* jugadorAnterior;
    ViewModel* viewModel;
    SDL_Rect* camara;
    SDL_Rect camaraStatic;
    SDL_Renderer* gRenderer;
    SDL_Window* window;
    LTexture texturaJugador;
    LTexture texturaSeleccionado;
    LTexture texturaPelota;
    LTexture texturaCancha;
    View_Mensajes panelMensaje;
    std::string mensaje;
};

#endif // VIEW_H
