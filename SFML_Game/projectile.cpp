
#include "projectile.h"

Projectile::Projectile()
{
    rect.setSize(sf::Vector2f(25,25));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Green);
}

void Projectile::update()
{
    if(direction == 1)
    {
        rect.move(0,-movementSpeed);
    }

    if(direction == 2)
    {
        rect.move(0,movementSpeed);
    }

    if(direction == 3)
    {
        rect.move(-movementSpeed,0);
    }

    if(direction == 4)
    {
        rect.move(movementSpeed,0);
    }

    counterLifetime++;
    if(counterLifetime >= lifeTime)
    {
        destroy = true;
    }
}
