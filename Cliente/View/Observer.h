#ifndef OBSERVER_H
#define OBSERVER_H

#include "../View/Entity.h"
#include "../View/Event.h"

class Observer
{
public:
    Observer();
    virtual ~Observer();
    virtual void onNotify(Entity& entity, Event& event) = 0;;

protected:

private:
};

#endif // OBSERVER_H
