
#include "enemy.h"


Enemy::Enemy()
{
    rect.setSize(sf::Vector2f(32,32));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Red);
    sprite.setTextureRect(sf::IntRect(49*4,0,49,49));
}

void Enemy::update()
{
    sprite.setPosition(rect.getPosition());
}

void Enemy::updateMovement()
{
    if(direction == 1)
    {
        rect.move(0,-movementSpeed);
    }
    else if(direction == 2)
    {
        rect.move(0,movementSpeed);
    }

    else if(direction == 3)
    {
        rect.move(-movementSpeed,0);
        sprite.setTextureRect(sf::IntRect((49*4)+49*counterWalking,0,49,49));
    }

    else if(direction == 4)
    {
        rect.move(movementSpeed,0);
        sprite.setTextureRect(sf::IntRect((49*6)+49*counterWalking,0,49,49));
    }
    else
    {
        //No movement
    }

    counterWalking++;
    if(counterWalking == 1)
    {
        counterWalking = 0;
    }

    counter++;

    if(counter >= movementLength)
    {
        counter = 0;
        direction = generateRandom(10);
    }
}

