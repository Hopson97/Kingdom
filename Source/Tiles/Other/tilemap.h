#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <memory>

#include "../Base/tile.h"

class Tile_Map
{
    using TilePtr   = std::unique_ptr<Tiles::Tile>;
    using TileVec   = std::vector<TilePtr>;

    friend class Level_Generator;

    public:
        Tile_Map();

        TilePtr&
        operator ()     ( const int x, const int y);

        TilePtr&
        at              ( const int x, const int y );

        TilePtr&
        operator ()     ( const sf::Vector2i& pos );

        TilePtr&
        at              ( const sf::Vector2i& pos );

        const double
        getFrictionAt   ( const sf::Vector2i& pos );

        const double
        getViscosityAt  ( const sf::Vector2i& pos );

        void
        addTile         ( TilePtr tile );

        void
        update          ( const float dt, const sf::Vector2i& playerPos, const std::vector<Light>& light );

        void
        draw            ( sf::RenderWindow& window, const sf::Vector2i& playerPos );

        void
        changeTile      ( TilePtr tile );

    private:
        TileVec m_tiles { Tiles::Info::MAP_SIZE * Tiles::Info::MAP_SIZE };

        constexpr static
        unsigned m_WIDTH = Tiles::Info::MAP_SIZE;
};

#endif // TILEMAP_H
