#include "Game.h"
#include "MainMenu.h"
#include "Button.h"
//#include "Game.cpp"


int main()
{
    //init MainMenu
    MainMenu menu;

    // init game
    if (menu.switchState == true) {
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
}