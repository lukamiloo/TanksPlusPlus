#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

 #include "Player.h"
 #include "Wall.h"
//#include "Player.cpp"
//#include "Wall.cpp"

#include "Player.h"
#include "Wall.h"

/*
 *	Game
 * 
 *	Main game class. All other class functions will be created, updated,
 *	and rendered here
 */
class Game {
private:
	// private variables
	sf::RenderWindow* window;
	sf::Event ev;
	Player* player;
	std::vector<Wall*> walls;
	// initialization functions
	void initVariables();
	void initWindow();
	void initPlayer();
	void initWalls();
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
