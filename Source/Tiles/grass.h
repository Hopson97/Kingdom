#ifndef GRASS_TILE_H
#define GRASS_TILE_H

#include "../game.h"
#include "Base/tile.h"

namespace Tiles
{

class Grass : public Tile
{
    public:
        Grass  ( const Game& game, const sf::Vector2i& pos,
                const Ecosystem ecosystem, const sf::Color& light = { 0, 0, 0 } );
};

} //namespace Tiles

#endif // GRASS_TILE_H
