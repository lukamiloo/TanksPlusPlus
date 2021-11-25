#include "Bullet.h"
#define M_PI 3.14159265358979323846

Bullet::Bullet(sf::Vector2f pos, float direction)
{
    this->initTexture();
    this->initBullet(pos, direction);
}

Bullet::~Bullet()
{
    //dtor

}

void Bullet::initTexture() {
	texture.loadFromFile("Textures/bullet.png");
}

void Bullet::shoot(int speed) {
    this->bullet.move(sinf((bullet.getRotation()+90)*M_PI/180) * speed, cosf((bullet.getRotation()+90)*M_PI/180)*-speed);
}

void Bullet::initBullet(sf::Vector2f pos, float direction) {
    this->bullet.setFillColor(sf::Color(178, 180, 183));
    this->bullet.setTexture(&texture);
    this->bullet.setSize(sf::Vector2f(25, 11.125));
    this->bullet.setPosition(pos);
    this->bullet.setRotation(direction);
    bounce = false;
}

void Bullet::moveBullet(sf::Vector2f pos, float direction) {
    this->bullet.setPosition(pos);
    this->bullet.setRotation(direction);
}

bool Bullet::getBounce() {
    return this->bounce;
}

void Bullet::setBounce(bool bounce) {
    this->bounce = bounce;
}

float Bullet::getX() {
    return this->bullet.getPosition().x;
}

float Bullet::getY() {
    return this->bullet.getPosition().y;
}

float Bullet::getRn() {
    return this->bullet.getRotation();
}

void Bullet::setRn(float rn) {
    this->bullet.setRotation(rn);
}

void Bullet::render(sf::RenderTarget* target) {
	target->draw(this->bullet);
}

