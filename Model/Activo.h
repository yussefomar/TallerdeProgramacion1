#ifndef ACTIVO_H
#define ACTIVO_H

#include <Estado.h>


class Activo : public Estado
{
public:
    Activo();
    virtual ~Activo();
    void move();
    bool estaActivo();
    void acelerar();

protected:

private:
};

#endif // ACTIVO_H
