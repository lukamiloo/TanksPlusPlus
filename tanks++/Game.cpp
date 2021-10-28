#include "Game.h"
#include "Player.h"

// constructor
Game::Game() {
	this->initVariables();
	this->initWindow();
	this->initPlayer();
	this->initWalls();
}

// destructor
Game::~Game() {
	delete this->window;
	delete this->player;
}

// initialize variables
void Game::initVariables() {
	this->window = nullptr;
}

// initialize window
void Game::initWindow() {
	// create window with 1920x1080 resolution
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "tanks++", sf::Style::Titlebar | sf::Style::Close);
	// set 60 fps
	this->window->setFramerateLimit(60);
}

// initialize player
void Game::initPlayer() {
	this->player = new Player();
}

// initialize walls
void Game::initWalls() {
	Wall* wallLeft = new Wall(50, 1080, 0, 0);
	Wall* wallRight = new Wall(50, 1080, 1870, 0);
	Wall* wallTop = new Wall(1920, 50, 0, 1030);
	Wall* wallBottom = new Wall(1920, 50, 0, 0);
	walls = { wallLeft, wallRight, wallTop, wallBottom };
}

/*
 *	running
 * 
 *	Checks if game window is still running
 * 
 *	returns:	true if running, false if not
 */
const bool Game::running() const {
	return this->window->isOpen();
}

/*
 *	pollEvents
 *
 *	Checks for event occurences
 */
void Game::pollEvents() {
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
			// window X button
			case sf::Event::Closed:
				this->window->close();
				break;
			// escape key
			case sf::Event::KeyPressed:
				if (this->ev.key.code == sf::Keyboard::Escape)
					window->close();
				break;
		}
	}
}

/*	
 *	update
 *
 *	Performs necessary game updates: time, score, etc. Continuosly call in a loop
 *	This is where all other class updates will go (Player, Bullet)
 */
void Game::update() {
	this->pollEvents();
	this->player->update();

	// unnecessary as walls do not get updated as of now
	// for (auto& wall : this->walls) {
	//     wall->update();
	// }
}

/*
 *	render
 * 
 *	Renders the screen with updated game state. Call after update is called.
 */
void Game::render() {
	this->window->clear(sf::Color::White);

	// all necessary renders go here
	this->player->render(this->window);
	for (auto& wall : this->walls) {
		wall->render(this->window);
	}

	this->window->display();
}