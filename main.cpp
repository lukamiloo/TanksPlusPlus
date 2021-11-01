#include "Game.h"
<<<<<<< HEAD
//#include "Game.cpp"
=======
>>>>>>> 4beeb6e11e7b417edc483c3fa9f0f57386598a97

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