#include "Game.h"
#include "MainMenu.h"
#include "Button.h"
//#include "Game.cpp"
#include <Windows.h>

int main()
{
    //init MainMenu
    MainMenu menu;

    // init game
    if (menu.switchState == true) {
        Game game;
        game.update();
        game.render();
        // main game loop
        while (game.running()) {
            // update
            game.update();
            //render
            game.render();
        }

        return 0;
    }
}