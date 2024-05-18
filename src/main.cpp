
// Startpoint for dev debug
#include "Game.h"

int main() {
    Game game(800, 600, "2D Platformer");
    game.run();

    return 0;
}


// Startpoint for win32 debug
int WinMain()
{
    Game game(800, 600, "2D Platformer");
    game.run();

    return 0;
}