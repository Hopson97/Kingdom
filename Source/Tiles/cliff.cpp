#include "cliff.h"

namespace Tiles
{

Cliff::Cliff( const Game& game, const sf::Vector2i& pos, const Ecosystem ecosystem )
:   Tile    ( game, pos, ecosystem )
{
    setInfo( game.getTileInfo( TILE_CLIFF ) );
}

} //namespace Tiles
