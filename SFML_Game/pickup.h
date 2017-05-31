#ifndef _pickup_
#define _pickup_

#include "entity.h"

class Pickup : public Entity
{
public:
    bool isCoin = true;
    int coinValue = 5;
    bool destroy = false;
    Pickup();
    void update();
};


#endif // _pickup_
