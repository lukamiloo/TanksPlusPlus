#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include <iostream>

/*
 *	Game
 * 
 *	Main game class. All other class functions will be created, updated,
 *	and rendered here
 */
class Game {
private:
	// private variables();
	sf::RenderWindow* window;
	sf::Event ev;

	// initialization functions
	void initVariables();
	void initWindow();
public:
	// constructor / destructor
	Game();
	virtual ~Game();

	// accessors
	const bool running() const;

	// game functions
	void pollEvents();
	void update();
	void render();
};

#endif
