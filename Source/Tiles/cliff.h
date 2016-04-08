#ifndef CLIFF_H
#define CLIFF_H

#include "tile.h"

namespace Tiles
{

class Cliff : public Tile
{
    public:
        Cliff( const Game& game, const sf::Vector2i& pos, const Ecosystem ecosystem );

    protected:

    private:
};

} //namespace Tiles

#endif // CLIFF_H
