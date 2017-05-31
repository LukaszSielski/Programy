#ifndef _enemy_
#define _enemy_

#include "entity.h"
#include "random.h"

class Enemy : public Entity
{
public:
    int hp = 3;
    int movementSpeed = 1;
    int attackDamage = 2;
    int counterWalking = 0;
    int movementLength = 150;
    int direction = 0;
    int counter = 0;
    bool alive = true;
    Enemy();
    void update();
    void updateMovement();

};





#endif // _enemy_


