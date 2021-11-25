#include "Heart.h"
#define M_PI 3.14159265358979323846

Heart::Heart()
{
    this->initTexture();
    this->initHealth();
}

Heart::~Heart()
{
    //dtor

}

void Heart::initTexture() {
	this->texture.loadFromFile("Textures/heart.png");
}


void Heart::initHealth() {
    this->heart.setFillColor(sf::Color::Red);
    this->heart.setTexture(&this->texture);
    this->heart.setSize(sf::Vector2f(512, 512));
    this->heart.setOrigin(this->heart.getSize().x / 2, this->heart.getSize().y / 2);
    this->heart.setPosition(500, 500);
}


void Heart::render(sf::RenderTarget* target) {
	target->draw(this->heart);
}

