#ifndef ICE_H
#define ICE_H

#include "Base/tile.h"
#include "Other/tilemap.h"

namespace Tiles
{

class Ice : public Tile
{
    public:
        Ice( Game& game, const sf::Vector2i& pos, Tile_Map* tileMap, const Ecosystem ecosystem  );

        void
        update  ( const float dt ) override;

    private:
        void
        melt();

    private:
        Tile_Map*   m_tileMap;
        Game*       m_game;

        sf::Clock m_meltTimer;

};

} //namespace tiles

#endif // ICE_H
