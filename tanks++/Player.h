#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

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

	// initialization functions
	void initTexture();
	void initSprite();
public:
	// constructor / destructor
	Player();
	virtual ~Player();

	// display functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif
