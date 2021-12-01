#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include <Windows.h>

// constructor
Game::Game() {
	this->initVariables();
	this->initWindow();
	this->initPlayer();
	this->initWalls();
	this->score = { 0,0 };
	this->roundStart = true;
}

// destructor
Game::~Game() {
	delete this->window;
	delete this->player;
	delete this->player2;
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
	//key bindings parameters go  (up, down, left, right, shoot)
	this->player = new Player(sf::Keyboard::Key::W, sf::Keyboard::Key::S, sf::Keyboard::Key::A, sf::Keyboard::Key::D, sf::Keyboard::Key::C, 400, 200);
	this->player2 = new Player(sf::Keyboard::Key::Up, sf::Keyboard::Key::Down, sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Keyboard::Key::M, 1500, 1700);
}

// initialize walls
void Game::initWalls() {
	Wall* wallLeft = new Wall(50, 1080, 0, 0);
	Wall* wallRight = new Wall(50, 1080, 1870, 0);
	Wall* wallTop = new Wall(1920, 50, 0, 1030);
	Wall* wallBottom = new Wall(1920, 50, 0, 0);
	walls = { wallLeft, wallRight, wallTop, wallBottom };
}

void Game::startRound() {
	sf::Clock gameClock;
	sf::Time delay = sf::seconds(2);
	sf::Time now = gameClock.getElapsedTime();
	sf::Time delta = gameClock.getElapsedTime();
	sf::Text countdown;
	sf::Font font;
	int sleep = 2000;
	int size = 184;

	if (!this->player->health || !this->player2->health) {
		if (!this->player->health) {
			this->message = "PLAYER 1 ELIMINATED";
			this->score[1]++;
			this->player->health++;
		}
		else {
			this->message = "PLAYER 2 ELIMINATED";
			this->score[0]++;
			this->player2->health++;
		}
		sleep = 2000;
		size = 92;
	}
	else if (this->message == "PLAYER 1 ELIMINATED" || this->message == "PLAYER 2 ELIMINATED") {
		this->message = "";
		sleep = 1500;
		this->initPlayer();
	}
	else if (this->message == "") {
		this->message = "READY";
	}
	else if (this->message == "READY") {
		this->message = "GO";
		sleep = 1000;
	}
	else if (this->message == "GO") {
		this->roundStart = false;
		this->message = "";
		sleep = 0;
	}

	font.loadFromFile("Fonts/score.ttf");
	countdown.setFont(font);
	countdown.setString(message);
	countdown.setCharacterSize(size);
	countdown.setFillColor(sf::Color::Black);
	sf::FloatRect countdownRect = countdown.getLocalBounds();
	countdown.setOrigin(countdownRect.left + countdownRect.width / 2.0f, countdownRect.top + countdownRect.height / 2.0f);
	countdown.setPosition(sf::Vector2f(1920 / 2.0f, 1080 / 2.0f));
	this->window->draw(countdown);
	this->window->display();
	Sleep(sleep);
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
 *	Performs necessary game updates: time, score, etc. Continuously call in a loop
 *	This is where all other class updates will go (Player, Bullet)
 */
void Game::update() {
	if (!roundStart) {
		this->pollEvents();
		this->player->update();
		this->player2->update();
		// player 1 bounds check
		if (this->player->getBounds().intersects(walls[0]->getBounds())) {
			this->player->movePos(sf::Vector2f(this->player->getSpeed(), 0));
		}
		if (this->player->getBounds().intersects(walls[1]->getBounds())) {
			this->player->movePos(sf::Vector2f(-this->player->getSpeed(), 0));
		}
		if (this->player->getBounds().intersects(walls[2]->getBounds())) {
			this->player->movePos(sf::Vector2f(0, -this->player->getSpeed()));
		}
		if (this->player->getBounds().intersects(walls[3]->getBounds())) {
			this->player->movePos(sf::Vector2f(0, this->player->getSpeed()));
		}
		// player 2 bounds check
		if (this->player2->getBounds().intersects(walls[0]->getBounds())) {
			this->player2->movePos(sf::Vector2f(this->player2->getSpeed(), 0));
		}
		if (this->player2->getBounds().intersects(walls[1]->getBounds())) {
			this->player2->movePos(sf::Vector2f(-this->player2->getSpeed(), 0));
		}
		if (this->player2->getBounds().intersects(walls[2]->getBounds())) {
			this->player2->movePos(sf::Vector2f(0, -this->player2->getSpeed()));
		}
		if (this->player2->getBounds().intersects(walls[3]->getBounds())) {
			this->player2->movePos(sf::Vector2f(0, this->player2->getSpeed()));
		}

		// collision check for player 1's bullets
		for (int i = 0; i < this->player->bulletVec.size(); i++) {
			if (this->player2->getBounds().intersects(this->player->bulletVec[i]->getBounds())) {
				this->player->bulletVec.erase(this->player->bulletVec.begin() + i);
				this->player->bulletVec.shrink_to_fit();
				this->player2->heartVec.pop_back();
				this->player2->health--;
				if (player2->health == 0) {
					this->roundStart = true;
					return;
				}
			}
		}

		// collision check for player 2's bullets
		for (int i = 0; i < this->player2->bulletVec.size(); i++) {
			if (this->player->getBounds().intersects(this->player2->bulletVec[i]->getBounds())) {
				this->player2->bulletVec.erase(this->player2->bulletVec.begin() + i);
				this->player2->bulletVec.shrink_to_fit();
				this->player->heartVec.pop_back();
				this->player->health--;
				if (player->health == 0) {
					this->roundStart = true;
					return;
				}
			}
		}
	}

}

/*
 *	render
 * 
 *	Renders the screen with updated game state. Call after update is called.
 */

void Game::drawBackground(sf::RenderTarget* target){
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("Textures/gameBackground.png");
	this->background.setTexture(backgroundTexture);
	target->draw(this->background);
}

void Game::drawScore(sf::RenderTarget* target)
{
	sf::Text score;
	sf::Font font;
	sf::String strScore = std::to_string(this->score[0]) + "\t" + std::to_string(this->score[1]);
	font.loadFromFile("Fonts/score.ttf");
	score.setString(strScore);
	score.setCharacterSize(64);
	score.setFont(font);
	score.setFillColor(sf::Color::Black);
	sf::FloatRect scoreRect = score.getLocalBounds();
	score.setOrigin(scoreRect.left + scoreRect.width / 2.0f, scoreRect.top + scoreRect.height / 2.0f);
	score.setPosition(sf::Vector2f(1920 / 2.0f, 100));
	target->draw(score);
}

void Game::render() {
	this->window->clear(sf::Color::White);
	// all necessary renders go here
	this->drawBackground(this->window);
	this->player->render(this->window);
	this->player2->render(this->window);
	for (auto& wall : this->walls) {
		wall->render(this->window);
	}
	this->drawScore(this->window);
	if (roundStart) this->startRound();
	else this->window->display();
}
