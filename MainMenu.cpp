//
// Created by User on 11/1/2021.
//

#include "MainMenu.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Button.h"
MainMenu::MainMenu() {
    this->initMainMenu();
}

void MainMenu::initMainMenu() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Tanks Plus Plus Menu");

    sf::Texture texture;

    //REMEMBER TO CHECK IF IT DOES NOT WORK AND GIVE ERROR
    texture.loadFromFile("Textures/background.png");
    sf::Sprite sprite(texture);

    Button playBtn({ 600,250 }, "Textures/playBtn.png");
    playBtn.setPosition({ 660, 550 });

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved) {
                if (playBtn.isMouseOver(window))
                    playBtn.setBackColor(sf::Color::Cyan);
                else
                    playBtn.setBackColor(sf::Color::White);
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (playBtn.isMouseOver(window)) {
                    switchState = true;
                    window.close();
                }
                    
                    
            }
        }

        window.clear();
        window.draw(sprite);
        playBtn.drawTo(window);
        window.display();
    }

}