#include "Thread.h"


Thread::Thread()
{
    //ctor
}

Thread::~Thread()
{
    //dtor
}

void Thread::empezarNuevoHilo() {
    this->hilo = std::thread(&Thread::procesoAEjecutar, this);
}

void Thread::bloquearHiloInvocante() {
    this->hilo.join();
}
