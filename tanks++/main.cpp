#include "Game.h"

int main()
{   
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