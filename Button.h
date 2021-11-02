#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
public:
	/**Create button with parmeters:
	* 1) size of button as Vector2f 
	* 2) texture as string name of texture file
	* */
	Button(sf::Vector2f, std::string);
	//set position of button after declaring button
	void setPosition(sf::Vector2f);
	/**
	* Draw button to refrenced window
	* parameter 1) &window is a refrence to current window
	* call function before window.display()
	*/
	void setBackColor(sf::Color color);
	void drawTo(sf::RenderWindow &window);
	//Check if mouse is on button 
	bool isMouseOver(sf::RenderWindow& window);
private:
	sf::RectangleShape button;
	sf::Texture texture;

};