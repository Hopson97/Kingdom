#include "grass.h"

namespace Tiles
{

Grass :: Grass ( const Game& game, const sf::Vector2i& pos, const Ecosystem ecosystem )
:   Tile ( game, pos, Info::Colours::grass, ecosystem,  true, false, 0.75)
{

}

} //namespace Tiles
