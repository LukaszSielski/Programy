
#include <SFML/Graphics.hpp>
#include <iostream>

#include "player.h"
#include "projectile.h"
#include "enemy.h"
#include "random.h"
#include "textDisplay.h"
#include "pickup.h"

using namespace std;

int main()
{
    //Window create
    sf::RenderWindow window(sf::VideoMode(1000,1000,32),"Sprajty");
    window.setFramerateLimit(60);

    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;

    int counter;
    int counter2;
    int counter3;

    //Loading texture for player
    sf::Texture walkTexture;
    if(!walkTexture.loadFromFile("spriteWalk.png"))
    {
        return EXIT_FAILURE;
    }

    //Loading texture for enemy
    sf::Texture enemyTexture;
    if(!enemyTexture.loadFromFile("enemy.png"))
    {
        return EXIT_FAILURE;
    }

    //Loading texture coin
    sf::Texture coinTexture;
    if(!coinTexture.loadFromFile("coin.jpg"))
    {
        return EXIT_FAILURE;
    }

    //Loading font
    sf::Font font;
    if(!font.loadFromFile("sansation.ttf"))
    {
        return EXIT_FAILURE;
    }
    //Text for coins
    sf::Text text("Gils : ",font,25);
    text.setColor(sf::Color::White);
    text.setCharacterSize(50);
    text.setPosition(0,0);



    //Player object
    Player player1;

    //Sprite set for player
    player1.sprite.setTexture(walkTexture);

    //Projectile vector array
    vector <Projectile>::const_iterator iter;
    vector <Projectile> projectileArray;


    //Enemy vector array
    vector <Enemy>::const_iterator iter4;
    vector <Enemy> enemyArray;

    //Text array

    vector <TextDisplay>::const_iterator iter8;
    vector <TextDisplay> textDisplayArray;

    //Coin array

    vector <Pickup>::const_iterator iter9;
    vector <Pickup> pickupArray;



    //Text object

    TextDisplay textDisplay1;
    textDisplay1.text.setFont(font);



    //Enemy object
    Enemy enemy1;
    enemy1.rect.setPosition(400,200);
    enemy1.sprite.setTexture(enemyTexture);
    enemyArray.push_back(enemy1);

     //Projectile object
    Projectile projectile1;

    //Coin object
    Pickup pickup1;
    pickup1.sprite.setTexture(coinTexture);
    pickup1.rect.setSize(sf::Vector2f(32,32));
    pickup1.rect.setPosition(500,500);
    pickupArray.push_back(pickup1);

    pickup1.rect.setPosition(500,700);
    pickupArray.push_back(pickup1);





    //Game loop
    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            //Close window by X
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            //Close window by Escape
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }

        }
        //Window clear
        window.clear();




        sf::Time elapsed1 = clock.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();
        sf::Time elapsed3 = clock3.getElapsedTime();

        //Player collide with pickup item

        counter = 0;
        for(iter9 = pickupArray.begin(); iter9 != pickupArray.end(); iter9++)
        {
            if(player1.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds()))
            {
                if(pickupArray[counter].isCoin == true)
                {
                    player1.gil += pickupArray[counter].coinValue;
                }
                pickupArray[counter].destroy = true;
            }
            counter++;
        }

        //Enemy collide with player

        if(elapsed2.asSeconds() >= 1)
        {
            clock2.restart();

            counter = 0;
            for(iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if(enemyArray[counter].rect.getGlobalBounds().intersects(player1.rect.getGlobalBounds()))
                {
                    //Text display
                    textDisplay1.text.setString(IntToString(enemyArray[counter].attackDamage));
                    textDisplay1.text.setPosition(player1.rect.getPosition());
                    textDisplayArray.push_back(textDisplay1);
                    player1.hp -= enemyArray[counter].attackDamage;
                }
                counter++;
            }
        }


        //Projectiles collisions with Enemies

        counter = 0;
        for(iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            counter2 = 0;
            for(iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if(projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
                {
                    projectileArray[counter].destroy = true;

                    //Text display
                    textDisplay1.text.setString(IntToString(projectileArray[counter].attackDamage));
                    textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition());
                    textDisplayArray.push_back(textDisplay1);

                    enemyArray[counter2].hp -= projectileArray[counter].attackDamage; //-= projectileArray[counter2].attackDamage;
                    if(enemyArray[counter2].hp <= 0)
                    {
                        enemyArray[counter2].alive = false;
                    }
                }
                counter2++;
            }
            counter++;
        }

        //Delete pickup item

        counter = 0;
        for(iter9 = pickupArray.begin(); iter9 != pickupArray.end(); iter9++)
        {
            if(pickupArray[counter].destroy == true)
            {
                pickupArray.erase(iter9);
                break;
            }
            counter++;
        }

        //Delete dead enemy

        counter = 0;
        for(iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            if(enemyArray[counter].alive == false)
            {
                cout<<"Enemy has died"<<endl;
                enemyArray.erase(iter4);
                break;
            }
            counter++;
        }

        //Delete projectile
        counter = 0;
        for(iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            if(projectileArray[counter].destroy == true)
            {
                projectileArray.erase(iter);
                break;
            }
            counter++;
        }

        //Delete textDisplay
        counter = 0;
        for(iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
        {
            if(textDisplayArray[counter].destroy == true)
            {
                 textDisplayArray.erase(iter8);
                 break;
            }

            counter++;
        }





        //Create enemy (Y)
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            enemy1.rect.setPosition(generateRandom(window.getSize().x),generateRandom(window.getSize().y));
            enemyArray.push_back(enemy1);
        }

        //Fires missiles (spacebar)
        if(elapsed1.asSeconds() >= 0.25 )
        {
            clock.restart();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,
                                             player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                projectile1.direction = player1.direction;
                projectileArray.push_back(projectile1);
            }
        }


        //Draw projectiles
        counter = 0;
        for(iter = projectileArray.begin(); iter!=projectileArray.end(); iter++)
        {
            projectileArray[counter].update();
            window.draw(projectileArray[counter].rect);
            counter++;
        }

        //Draw enemy
        counter = 0;
        for(iter4 = enemyArray.begin(); iter4!=enemyArray.end(); iter4++)
        {
            enemyArray[counter].update();
            enemyArray[counter].updateMovement();
            //window.draw(enemyArray[counter].rect);
            window.draw(enemyArray[counter].sprite);
            counter++;
        }

        //Draw coin

        counter = 0;
        for(iter9 = pickupArray.begin(); iter9!=pickupArray.end(); iter9++)
        {
            pickupArray[counter].update();
            window.draw(pickupArray[counter].sprite);
            counter++;
        }



        //Player update
        player1.update();


        //Player movement update
        player1.updateMovement();

        //Player draw
        window.draw(player1.sprite);

        //Draw text
        counter = 0;
        for(iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
        {
            textDisplayArray[counter].update();
            window.draw(textDisplayArray[counter].text);
            counter++;
        }


        //Gil
        text.setString("Gil : " + IntToString(player1.gil));
        window.draw(text);

        //Display in window
        window.display();
    }

    return 0;
}
