#ifndef GRASS_TILE_H
#define GRASS_TILE_H

#include "game.h"
#include "tile.h"

namespace Tiles
{

class Grass : public Tile
{
    public:
        Grass  ( const Game& game, const sf::Vector2i& pos, const Ecosystem ecosystem );
};

} //namespace Tiles

#endif // GRASS_TILE_H
