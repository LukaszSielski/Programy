
#include "pickup.h"



Pickup::Pickup()
{
    rect.setSize(sf::Vector2f(32,32));
    rect.setFillColor(sf::Color::Yellow);
    rect.setPosition(0,0);
    //sprite.setTextureRect(sf::IntRect(0,0,32,32));

}

void Pickup::update()
{
    sprite.setPosition(rect.getPosition());
}



