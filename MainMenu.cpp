//
// Created by User on 11/1/2021.
//

#include "MainMenu.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Audio.hpp>
#include "Button.h"

MainMenu::MainMenu() {
    this->initMainMenu();
}

MainMenu::~MainMenu() {
    //dtor
}

void MainMenu::initMainMenu() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Tanks Plus Plus Menu");

    sf::Texture texture;

    //button press
    bool buttonSoundHasPlayed = false;
    sf::SoundBuffer btnSoundBuffer;
    sf::Sound btnSound;
    if(!btnSoundBuffer.loadFromFile("Textures/buttonSound.ogg")) {
        std::cout << "Cant find buttonSound.ogg" <<std::endl;
    }
    btnSound.setBuffer(btnSoundBuffer);

    //background main menu music
    sf::Music music;
    if (!music.openFromFile("Textures/MainMenuMadeSong.ogg"))
        std::cout << "Cant find MainMenuMadeSong.ogg" <<std::endl;
    music.play();
    music.setLoop(true);

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
                if (playBtn.isMouseOver(window)) {
                    playBtn.setBackColor(sf::Color::Cyan);
                    //only play button sound once
                    if(!buttonSoundHasPlayed) {
                        btnSound.play();
                        buttonSoundHasPlayed = true;
                    }
                }
                else {
                    playBtn.setBackColor(sf::Color::White);
                    //reset button sound if user mouse leaves the button
                    buttonSoundHasPlayed = false;
                }

            }
            if (event.type == sf::Event::MouseButtonPressed) {
                btnSound.play();
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