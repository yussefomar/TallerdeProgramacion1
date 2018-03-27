#include <iostream>

using namespace std;


void obtenerControles() {
    cout << "obtenerControles" << endl;
}

void actualizarModelo() {
    cout << "actualizarModelo" << endl;
}

void renderizar() {
    cout << "renderizar" << endl;
}

int main()
{
    while(true)
    {
        obtenerControles();
        actualizarModelo();
        renderizar();
    }

    cout << "Hello world!" << endl;
    return 0;
}
