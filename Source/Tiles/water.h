#ifndef WATER_TILE_H
#define WATER_TILE_H

#include "game.h"
#include "tile_types.h"
#include "tilemap.h"

namespace Tiles
{

class Water : public Tile
{
    public:
        Water       ( Game& game, const sf::Vector2i& pos, Tile_Map& tileMap, const Ecosystem ecosystem );

        void
        update      ( const float dt ) override;

        void
        steppedOn   () override;

    private:
        Game* m_game;
        float m_time;

        Tile_Map* m_tileMap;

        sf::Clock m_txrClock;
};

} //namespace Tiles

#endif // WATER_TILE_H
