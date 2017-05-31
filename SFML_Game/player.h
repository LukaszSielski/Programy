#ifndef _player_
#define _player_

#include "entity.h"

class Player : public Entity
{
public:
    int movementSpeed = 2;
    int counterWalking = 0;
    int direction = 0; // 1- up, 2-down, 3-left, 4-right
    int hp = 10;
    int gil = 0;


    Player();
    void update();
    void updateMovement();
};


#endif // _player_
