#ifndef WATER_TILE_H
#define WATER_TILE_H

#include "../game.h"
#include "Base/tile.h"
#include "Other/tilemap.h"

namespace Tiles
{

class Water : public Tile
{
    public:
        Water       ( Game& game, const sf::Vector2i& pos, Tile_Map& tileMap,
                     const Ecosystem ecosystem, const sf::Color& light = { 0, 0, 0 } );

        void update		( const float dt ) override;

        void steppedOn	() override;

    private:
        Game* m_game;
        float m_time;

        Tile_Map* m_tileMap;

        sf::Clock m_txrClock;
};

} //namespace Tiles

#endif // WATER_TILE_H
