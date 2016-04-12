#ifndef ICE_H
#define ICE_H

#include "Base/tile.h"
#include "Other/tilemap.h"

namespace Tiles
{

class Ice : public Tile
{
    public:
        Ice( Game& game, const sf::Vector2i& pos, Tile_Map* tileMap,
            const Ecosystem ecosystem, const sf::Color& light = { 0, 0, 0 } );

        void
        update      ( const float dt, const std::vector<Light>& lights ) override;

        void
        steppedOn   ();

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
