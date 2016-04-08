#include "cliff.h"

namespace Tiles
{

Cliff::Cliff( const Game& game, const sf::Vector2i& pos, const Ecosystem ecosystem )
:   Tile    ( game, pos, Info::Colours::cliff, ecosystem, false, false, 0, 0 )
{

}

} //namespace Tiles
