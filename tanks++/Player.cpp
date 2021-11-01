#include "Player.h"

// constructor
Player::Player() {
	initTexture();
	initSprite();
}

// destructor
Player::~Player() {

}
// hey hey

// initialize player texture
void Player::initTexture() {
	this->texture.loadFromFile("Textures/tank.png");
}

// initialize player model
void Player::initSprite() {
	this->player.setTexture(this->texture);
	this->player.scale(0.2f, 0.2f);
	this->player.setPosition(860, 540);
}

/*
 *	update
 * 
 *	Updates player position, orientation based on key presses. Called by Game class update()
 */
void Player::update() {
	// TODO movement on key press
}

/*
 *	render
 * 
 *	Renders the screen with updated player state. Call after Player class update()
 * 
 *	Param:	target	specific RenderWindow to draw to
 */
void Player::render(sf::RenderTarget* target) {
	target->draw(this->player);
}