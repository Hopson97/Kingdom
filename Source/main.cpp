// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#include "game.h"
#include <iostream>

#include "swimmable.h"

/*
    To do:
        *   Player movement feels odd. The player is too slow on grass and too fast on ice.
            Needs to be able to move but still have friction on the tiles.
        *   Do something about the repeated code in the "Tile_Collidable" class
        *   Create a shark texture for the Shark class
        *   Combine spawns_ground and spawns_sea somehow
        *   Improve level gen
        *   Animation for the "swimmable" class ( Res/Effects/Water Splash.png") or make the particle system look good
        *   Zombies get stuck on edge of tiles. (eg, grass to water), why?
        *   Enemy AI component
        *   Comments
*/


int main()
{
    srand(time(NULL));
    std::cout << "vertex size: " << sizeof(Component::Swimmable) << std::endl;

    Game game;
    game.runLoop();

    return 0;
}



































