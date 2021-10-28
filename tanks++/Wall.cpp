#include "Wall.h"

// constructor
Wall::Wall(float l, float w, float posX, float posY) {
	this->posX = posX;
	this->posY = posY;
	this->initShape(l, w);
}

// destructor
Wall::~Wall() {
}


// initialize wall
void Wall::initShape(float l, float w) {
	this->rect.setSize(sf::Vector2f(l, w));
	this->rect.setPosition(sf::Vector2f(posX, posY));
	this->rect.setFillColor(sf::Color::Black);
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