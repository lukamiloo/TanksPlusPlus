#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Wall {
	public:
		Wall(float l, float w, float posX, float posY);
		virtual ~Wall();
		sf::FloatRect getBounds();
		void update();
		void render(sf::RenderWindow* target);
		
	private:
		sf::RectangleShape rect;
		sf::Texture texture;
		float posX, posY;

		void initTexture();
		void initShape(float l, float w);

};

#endif
