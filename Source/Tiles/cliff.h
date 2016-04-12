#ifndef CLIFF_H
#define CLIFF_H

#include "Base/tile.h"

namespace Tiles
{

class Cliff : public Tile
{
    public:
        Cliff( const Game& game, const sf::Vector2i& pos,
               const Ecosystem ecosystem, const sf::Color& light = { 0, 0, 0 } );

    protected:

    private:
};

} //namespace Tiles

#endif // CLIFF_H
