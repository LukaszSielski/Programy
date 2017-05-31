
#include "textDisplay.h"

TextDisplay::TextDisplay()
{
  text.setColor(sf::Color::Red);
  text.setCharacterSize(30);
  text.setPosition(0,0);

  text.setPosition(300,300);
  text.setString(myString);
}

void TextDisplay::update()
{
    text.move(0,-movementSpeed);

    counter++;

    if(counter >= lifeTime)
    {
        destroy = true;
    }
}



