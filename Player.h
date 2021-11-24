#ifndef PLAYER_H
#define PLAYER_H

#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>
#include "Bullet.h"

/*
 *	Player
 *
 *	Player class. Movement, controls, and textures will be handled here
 */
class Player {
private:
	// private variables
	sf::Sprite player;
	sf::Texture texture;
	float movementSpeed;
	bool isFiring;
	std::vector<Bullet> bulletVec;
	// initialization functions
	void initTexture();
	void initSprite();
	void initBullet();
public:
	// constructor / destructor
	Player();
	virtual ~Player();
	//move player
	void move(const float xDir, const float yDir);

	// display functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif
