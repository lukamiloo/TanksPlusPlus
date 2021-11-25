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
	this->isFiring = false;
	tickRate = timer.restart();
	this->movementSmooth = ((float)tickRate.asMilliseconds() / 1000);
	clock.restart();
}

/*
 *	update
 * 
 *	Updates player position, orientation based on key presses. Called by Game class update()
 */
void Player::update() {
	// TODO movement on key press
	if(sf:: Keyboard::isKeyPressed(sf::Keyboard::W))//move forware in direction of front of tank
		this->player.move(sinf(player.getRotation()*M_PI/180) * 4, cosf(player.getRotation()*M_PI/180)* -4 );
	if(sf:: Keyboard::isKeyPressed(sf::Keyboard::S))//move forware in direction of back of tank
		this->player.move(sinf(player.getRotation()*M_PI/180) * -4, cosf(player.getRotation()*M_PI/180) * 4);
	if(sf:: Keyboard::isKeyPressed(sf::Keyboard::D))//rotate clockwise
		this->player.rotate(2.f);
	if(sf:: Keyboard::isKeyPressed(sf::Keyboard::A))//rotate counterclockwise
		this->player.rotate(-2.f);
	
	if(sf:: Keyboard::isKeyPressed(sf::Keyboard::C)){//shoot
		this->isFiring = true;
	}

	if(this->isFiring){

		if( bulletVec.size() < 1){
			Bullet newBullet;
			newBullet.moveBullet(sf::Vector2f(player.getPosition().x + (75 * sinf(player.getRotation()*M_PI/180)), player.getPosition().y - (75 * cosf(player.getRotation()*M_PI/180))), player.getRotation()-90);
			this->bulletVec.push_back(newBullet);
			isFiring = false;
		}

		if (clock.getElapsedTime().asSeconds() > 0.5){
			Bullet newBullet;
			newBullet.moveBullet(sf::Vector2f(player.getPosition().x + (75 * sinf(player.getRotation()*M_PI/180)), player.getPosition().y - (75 * cosf(player.getRotation()*M_PI/180))), player.getRotation()-90);
			this->bulletVec.push_back(newBullet);
			clock.restart();
			isFiring = false;
		}
	}

	for(int i = 0; i < bulletVec.size(); i++){
		if(bulletVec[i].getX() > 1850 || bulletVec[i].getX() < 70 || bulletVec[i].getY() > 1010 || bulletVec[i].getY() < 70){
			if(bulletVec[i].getBounce()){
				bulletVec.erase(bulletVec.begin() + i);
				isFiring = false;
			} else {
				bulletVec[i].setBounce(true);
			}
		}
	}
}

/*
 *	move
 * 
 *	moves sprite based on x coordinate and y coordinate input
 *	allows dev to modify movement speed
 */
void Player::move(const float xDir, const float yDir){
	this->player.move(this->movementSpeed * xDir * this->movementSmooth, this->movementSpeed * yDir * this->movementSmooth);
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
	
	for (int i = 0; i < bulletVec.size(); i++) {
		this->bulletVec[i].render(target);
		if(!bulletVec[i].getBounce()){
			this->bulletVec[i].shoot(10);
		} else {	
			this->bulletVec[i].shoot(-10);
		}
	}
}