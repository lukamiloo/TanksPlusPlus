#include "Game.h"
#include "MainMenu.h"
//#include "Game.cpp"


int main()
{
    //init MainMenu
    MainMenu menu;

    // init game
    Game game;

    // main game loop
    while (game.running()) {
        // update
        game.update();
        //render
        game.render();
    }

    return 0;
}