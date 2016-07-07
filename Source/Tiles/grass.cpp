#include "grass.h"

namespace Tiles
{

Grass :: Grass ( const Game& game, const sf::Vector2i& pos,
                 const Ecosystem ecosystem, const sf::Color& light )
:   Tile        ( game, pos, ecosystem, light  )
{
    setInfo( game.getTileInfo( TILE_GRASS ) );
    setColor( sf::Color::Green );
}


} //namespace Tiles

/**

                const bool walkable,
                const bool swimmable,
                const double friction,
                const double viscosity );
*/
