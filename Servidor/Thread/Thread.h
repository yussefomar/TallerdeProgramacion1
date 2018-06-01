#ifndef THREAD_H
#define THREAD_H
#include <iostream>
#include <vector>
#include <thread>

class Thread
{
    public:
        Thread();
        virtual ~Thread();
        void empezarNuevoHilo();
        void bloquearHiloInvocante();
        virtual void procesoAEjecutar() = 0;

    protected:
        std::thread hilo;

    private:
};

#endif // THREAD_H
