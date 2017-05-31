#ifndef _textDisplay_
#define _textDisplay_
#include "entity.h"

class TextDisplay : public Entity
{
public:
    int movementSpeed = 2;
    int counter = 0;
    bool destroy = false;
    int lifeTime = 50;
    string myString = "Default";
    TextDisplay();
    void update();
};

#endif // _textDisplay_
