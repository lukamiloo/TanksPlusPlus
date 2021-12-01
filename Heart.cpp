#include "Heart.h"
#define M_PI 3.14159265358979323846

Heart::Heart(sf::Vector2f pos, sf::Color color)
{
    this->initTexture();
    this->initHealth(pos, color);
}

Heart::~Heart()
{
    //dtor
}

void Heart::initTexture() {
	this->texture.loadFromFile("Textures/heart.png");
}


void Heart::initHealth(sf::Vector2f pos, sf::Color color) {
    this->heart.setFillColor(color); //pass in color as argument
    this->heart.setTexture(&this->texture);
    this->heart.setSize(sf::Vector2f(32, 32));
    this->heart.setOrigin(this->heart.getSize().x / 2, this->heart.getSize().y / 2);
    this->heart.setPosition(pos);
}


void Heart::render(sf::RenderTarget* target) {
	target->draw(this->heart);
}

