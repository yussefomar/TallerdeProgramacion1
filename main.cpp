#include "View/View.h"
#include "Controller/Controller.h"
#include "Model/Model.h"


int main(int argc, char* args[])
{
    View view;
    Controller controller;
    Model model;

    model.addObserver(&view);
    controller.setModel(model);
    view.setModel(model);

    while(!controller.quitPressed())
    {
        controller.processInput();
        model.update();
        view.render();
    }


    return 0;

}
