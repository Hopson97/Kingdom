#include "grass.h"

namespace Tiles
{

Grass :: Grass ( const Game& game, const sf::Vector2i& pos, const Ecosystem ecosystem )
:   Tile    ( game, pos, ecosystem )
{
    setInfo( game.getTileInfo( TILE_GRASS ) );
}


} //namespace Tiles

/**

                const bool walkable,
                const bool swimmable,
                const double friction,
                const double viscosity );
*/
