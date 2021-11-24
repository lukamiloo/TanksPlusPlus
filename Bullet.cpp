#include "Bullet.h"
#define M_PI 3.14159265358979323846

Bullet::Bullet()
{
    this->initTexture();
    this->initBullet();
}

void Bullet::initTexture() {
	this->texture.loadFromFile("Textures/bullet.png");
}
// void Bullet::shoot(sf::Vector2f direction, sf::Vector2f position, float speed) {
//     this->direction = direction;
//     this->speed = speed;
//     this->bullet.setPosition(position);
// }

void Bullet::shoot(int speed) {
    this->bullet.move(sinf((bullet.getRotation()+90)*M_PI/180) * speed, cosf((bullet.getRotation()+90)*M_PI/180)*-speed);
}

void Bullet::initBullet() {
    this->bullet.setFillColor(sf::Color(178, 180, 183));
    this->bullet.setOutlineColor(sf::Color(0, 0, 0));
    this->bullet.setTexture(&this->texture);
    this->bullet.setSize(sf::Vector2f(25, 11.125));
}

void Bullet::makeBullet(sf::Vector2f pos, float direction) {
    this->bullet.setPosition(pos);
    this->bullet.setRotation(direction);
}
void Bullet::render(sf::RenderTarget* target) {
	target->draw(this->bullet);
}

