#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>

class Bullet
{
    public:
        Bullet();
        //Bullet(sf::Vector2f, sf::Vector2f, float);
        void render(sf::RenderTarget* target);
        //void shoot(sf::Vector2f, sf::Vector2f, float);
        void makeBullet(sf::Vector2f, float);
        void initTexture();
        void initBullet();
        void shoot(int);
    private:
        sf::RectangleShape bullet;
        sf::Texture texture;
};

#endif