#include "Player.h"
#define M_PI 3.14159265358979323846

// constructor
Player::Player() {
	this->movementSpeed = 20;
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
	this->player.scale(0.15f, 0.15f);
	this->player.setPosition(860, 540);
	this->player.setOrigin(sf::Vector2f(player.getTexture()->getSize().x * 0.5, player.getTexture()->getSize().y * 0.5));//setting origin to the middle of the sprite
}

/*
 *	update
 * 
 *	Updates player position, orientation based on key presses. Called by Game class update()
 */
void Player::update() {
	// TODO movement on key press
	if(sf:: Keyboard::isKeyPressed(sf::Keyboard::W))//move forware in direction of front of tank
		this->player.move(sinf(player.getRotation()*M_PI/180) * 4, cosf(player.getRotation()*M_PI/180)*-4);
	if(sf:: Keyboard::isKeyPressed(sf::Keyboard::S))//move forware in direction of back of tank
		this->player.move(sinf(player.getRotation()*M_PI/180) *-4, cosf(player.getRotation()*M_PI/180)*4);
	if(sf:: Keyboard::isKeyPressed(sf::Keyboard::D))//rotate clockwise
		this->player.rotate(2.f);
	if(sf:: Keyboard::isKeyPressed(sf::Keyboard::A))//rotate counterclockwise
		this->player.rotate(-2.f);
	
	if(sf:: Keyboard::isKeyPressed(sf::Keyboard::C)){//shoot
		this->isFiring = true;
	}
	
	if(this->isFiring){
		if(bulletVec.size() < 2){
			Bullet newBullet;
			newBullet.initTexture();
			newBullet.initBullet();
			newBullet.makeBullet(sf::Vector2f(player.getPosition().x + (75 * sinf(player.getRotation()*M_PI/180)), player.getPosition().y - (75 * cosf(player.getRotation()*M_PI/180))), player.getRotation()-90);
			this->bulletVec.push_back(newBullet);
			isFiring = false;
		}
	}

	//For the bullet when doing collision all you need to add is bulletVec.erase(bulletVec.begin());
	
}

/*
 *	move
 * 
 *	moves sprite based on x coordinate and y coordinate input
 *	allows dev to modify movement speed
 */
void Player::move(const float xDir, const float yDir){
	this->player.move(this->movementSpeed * xDir, this->movementSpeed * yDir);
}

// int Player::getX() {
// 	return this->player.getPosition().x;
// }

// int Player::getY() {
// 	return this->player.getPosition().y;
// }

/*
 *	render
 * 
 *	Renders the screen with updated player state. Call after Player class update()
 * 
 *	Param:	target	specific RenderWindow to draw to
 */
void Player::render(sf::RenderTarget* target) {
	target->draw(this->player);
	
	for (int i = 0; i < bulletVec.size(); i++) {
		this->bulletVec[i].render(target);
		this->bulletVec[i].shoot(10);
	}
}