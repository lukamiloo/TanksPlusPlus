#include "Wall.h"

// constructor
Wall::Wall(float l, float w, float posX, float posY) {
	this->posX = posX;
	this->posY = posY;
	this->initTexture();
	this->initShape(l, w);
}

// destructor
Wall::~Wall() {
}

// initialize texture
void Wall::initTexture() {
	this->texture.loadFromFile("Textures/wall.png");
	this->texture.setRepeated(true);
}

// initialize wall
void Wall::initShape(float l, float w) {
	this->rect.setSize(sf::Vector2f(l, w));
	this->rect.setPosition(sf::Vector2f(posX, posY));
	this->rect.setTexture(&this->texture);
	// not too sure how setTextureRect works still
	this->rect.setTextureRect(sf::IntRect(0, 0, l*4, w*4));
}

/*
 *	update
 * 
 *	Update Wall. Will most likely be useless unless moving/breakable walls are added.
 */
void Wall::update() {

}

/*
 *	render
 * 
 *	Renders the screen with current wall state. Will most likely be useless past first call for
 *	the same reason as above.
 * 
 *	Param:	target	specific RenderWindow to draw to
 */
void Wall::render(sf::RenderWindow* target) {
	target->draw(this->rect);
}