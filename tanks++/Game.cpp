#include "Game.h"
#include "Player.h"

// constructor
Game::Game() {
	this->initVariables();
	this->initWindow();
}

// destructor
Game::~Game() {
	delete this->window;
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
}

/*
 *	render
 * 
 *	Renders the screen with updated game state. Call after update is called.
 */
void Game::render() {
	this->window->clear(sf::Color::White);

	// all necessary renders go here

	this->window->display();
}