#ifndef WALL_H
#define WALL_H

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include <iostream>

class Wall {
private:
	sf::RectangleShape rect;
	float posX, posY;

	void initShape(float l, float w);
public:
	Wall(float l, float w, float posX, float posY);
	virtual ~Wall();

	void update();
	void render(sf::RenderWindow* target);
};

#endif
