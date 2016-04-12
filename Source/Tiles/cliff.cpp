#include "cliff.h"

namespace Tiles
{

Cliff::Cliff( const Game& game, const sf::Vector2i& pos,
              const Ecosystem ecosystem, const sf::Color& light )
:   Tile        ( game, pos, ecosystem, light  )
{
    setInfo( game.getTileInfo( TILE_CLIFF ) );
}

} //namespace Tiles
