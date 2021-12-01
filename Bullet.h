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
        Bullet(sf::Vector2f, float);
        virtual ~Bullet();
        void render(sf::RenderTarget* target);
        void moveBullet(sf::Vector2f, float);
        void shoot(int);
        float getX();
        float getY();
        float getRn();
        void setRn(float);
        bool getBounce();
        void setBounce(bool);
        sf::FloatRect getBounds();
    private:
        sf::RectangleShape bullet;
        sf::Texture texture;
        bool bounce;
        void initTexture();
        void initBullet(sf::Vector2f, float);
};

#endif