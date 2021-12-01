#include "Player.h"
#define M_PI 3.14159265358979323846

// constructor
Player::Player(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey, sf::Keyboard::Key leftKey, sf::Keyboard::Key rightKey, sf::Keyboard::Key shootKey, float pos, int heartPos) {
	this->movementSpeed = 20;
	this->pos = pos;
	this->heartPos = heartPos;
	this->upKey = upKey;
	this->downKey = downKey;
	this->leftKey = leftKey;
	this->rightKey = rightKey;
	this->shootKey = shootKey;
	this->bulletVec = {};
	this->heartVec = {};
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
	if (this->upKey == sf::Keyboard::Key::W) {
		this->player.setPosition(200, 540);
	}
	else {
		this->player.setPosition(1700, 540);
	}
	this->player.setOrigin(sf::Vector2f(player.getTexture()->getSize().x * 0.5, player.getTexture()->getSize().y * 0.5));//setting origin to the middle of the sprite
	this->isFiring = false;
	tickRate = timer.restart();
	this->health = 3;
	this->movementSmooth = ((float)tickRate.asMilliseconds() / 1000);
	clock.restart();

	for (int i = 0; i < this->health; i++) {
		this->heartVec.push_back(new Heart(sf::Vector2f(i * 50 + this->heartPos, 1000), sf::Color::Red));
	}
}

void Player::updateInput(){
	// TODO movement on key press
	if(sf:: Keyboard::isKeyPressed(this->upKey))//move forware in direction of front of tank
		this->player.move(sinf(player.getRotation()*M_PI/180) * 4, cosf(player.getRotation()*M_PI/180)* -4 );
	if(sf:: Keyboard::isKeyPressed(this->downKey))//move forware in direction of back of tank
		this->player.move(sinf(player.getRotation()*M_PI/180) * -4, cosf(player.getRotation()*M_PI/180) * 4);
	if(sf:: Keyboard::isKeyPressed(this->rightKey))//rotate clockwise
		this->player.rotate(2.f);
	if(sf:: Keyboard::isKeyPressed(this->leftKey))//rotate counterclockwise
		this->player.rotate(-2.f);
	
	if(sf:: Keyboard::isKeyPressed(this->shootKey) && clock.getElapsedTime().asSeconds() > 0.75){//shoot
		this->isFiring = true;
	}
}

/*
 *	update
 * 
 *	Updates player position, orientation based on key presses. Called by Game class update()
 */
void Player::update() {
	// TODO movement on key press
	this->updateInput();

	//When the collision is done to delete the heart just do this->heartVec.pop_back(); or this->heartVec.erase(this->heartVec.begin());

	if(this->isFiring){ 

		if(bulletVec.size() < 3 && clock.getElapsedTime().asSeconds() > 0.75){
			this->bulletVec.push_back(new Bullet(sf::Vector2f(player.getPosition().x + (75 * sinf(player.getRotation()*M_PI/180)), player.getPosition().y - (75 * cosf(player.getRotation()*M_PI/180))), player.getRotation()-90));
			clock.restart();
			this->isFiring = false;
		}
	}

	for(int i = 0; i < this->bulletVec.size(); i++){
		if(this->bulletVec[i]->getX() > 1850 || this->bulletVec[i]->getX() < 70 || this->bulletVec[i]->getY() > 1010 || this->bulletVec[i]->getY() < 70){
			if(this->bulletVec[i]->getBounce()){
				bulletVec.erase(bulletVec.begin() + i);
				bulletVec.shrink_to_fit();
				isFiring = false;
			} else {
				this->bulletVec[i]->setBounce(true);
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

void Player::movePos(sf::Vector2f vec){
	this->player.move(vec.x, vec.y);
}

//get speed of player
float Player::getSpeed(){
	return this->movementSpeed;
}
//get position of player
sf::Vector2f Player::getPosition(){
	return this->player.getPosition();
}

sf::FloatRect Player::getBounds() {
	return this->player.getGlobalBounds();
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
		this->bulletVec[i]->render(target);
		if(!bulletVec[i]->getBounce()){
			this->bulletVec[i]->shoot(10);
		} else {	
			this->bulletVec[i]->shoot(-10);
		}
	}

	for (int i = 0; i < heartVec.size(); i++) {
		this->heartVec[i]->render(target);
	}
}