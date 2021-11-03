//
// Created by User on 11/1/2021.
//

#include "MainMenu.h"
#include <SFML/Graphics.hpp>
#include <cmath>
MainMenu::MainMenu() {
    this->initMainMenu();
}

void MainMenu::initMainMenu() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Tanks Plus Plus Menu");

    sf::Texture texture;

    //REMEMBER TO CHECK IF IT DOES NOT WORK AND GIVE ERROR
    texture.loadFromFile("Textures/background.png");
    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

}