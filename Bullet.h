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
        virtual ~Bullet();
        void render(sf::RenderTarget* target);
        void moveBullet(sf::Vector2f, float);
        void shoot(int);
        float getX();
        float getY();
        float getRn();
        bool getBounce();
        void setBounce(bool);
    private:
        sf::RectangleShape bullet;
        sf::Texture texture;
        bool bounce;
        void initTexture();
        void initBullet();
};

#endif