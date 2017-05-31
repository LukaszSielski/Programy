
#ifndef _projectile_
#define _projectile_

#include "entity.h"


class Projectile : public Entity
{
public:
    int movementSpeed = 10;
    int attackDamage = 1;
    int direction = 0; // 1- up, 2-down, 3-left, 4-right
    int counterLifetime = 0;
    int lifeTime = 10;
    bool destroy = false;
    Projectile();
    void update();
};
#endif // _projectile_
