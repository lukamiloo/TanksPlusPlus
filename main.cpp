#include "Game.h"
#include "MainMenu.h"
<<<<<<< HEAD
=======
#include "Button.h"
>>>>>>> 138ffcf7a50bee8269305974034a502c4112215d
//#include "Game.cpp"


int main()
{
    //init MainMenu
    MainMenu menu;

    // init game
<<<<<<< HEAD
    Game game;

    // main game loop
    while (game.running()) {
        // update
        game.update();
        //render
        game.render();
    }

    return 0;
=======
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
>>>>>>> 138ffcf7a50bee8269305974034a502c4112215d
}