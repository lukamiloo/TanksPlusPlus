#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

//Button::Button(){}
Button::Button(sf::Vector2f size, std::string textureName) {
	button.setSize(size);
	texture.loadFromFile(textureName);
	button.setTexture(&texture);
	
}

void Button::setPosition(sf::Vector2f pos) {
	button.setPosition(pos);
}

void Button::setBackColor(sf::Color color) {
	button.setFillColor(color);
}

void Button::drawTo(sf::RenderWindow &window) {
	window.draw(button);
}

bool Button::isMouseOver(sf::RenderWindow& window) {
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;
	float btnPosX = button.getPosition().x;
	float btnPosY = button.getPosition().y;
	float btnPosW = button.getPosition().x + button.getLocalBounds().width;
	float btnPosH = button.getPosition().y + button.getLocalBounds().height;

	if (mouseX < btnPosW && mouseX > btnPosX && mouseY < btnPosH && mouseY > btnPosY) {
		return true;
	}
	return false;
}