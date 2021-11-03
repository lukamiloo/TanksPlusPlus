#ifndef PLAYER_H
#define PLAYER_H

<<<<<<< HEAD
#include "Player.h"
=======
>>>>>>> 138ffcf7a50bee8269305974034a502c4112215d
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
<<<<<<< HEAD
#include <math.h>
=======
>>>>>>> 138ffcf7a50bee8269305974034a502c4112215d

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
<<<<<<< HEAD
	float movementSpeed;
=======
>>>>>>> 138ffcf7a50bee8269305974034a502c4112215d

	// initialization functions
	void initTexture();
	void initSprite();
public:
	// constructor / destructor
	Player();
	virtual ~Player();
<<<<<<< HEAD
	//move player
	void move(const float xDir, const float yDir);
=======

>>>>>>> 138ffcf7a50bee8269305974034a502c4112215d
	// display functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif
