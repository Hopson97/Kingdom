#ifndef LEVELGEN_H
#define LEVELGEN_H

#include "../Other/tilemap.h"
#include "../Base/tile_types.h"
#include "game.h"
#include "rand.h"
#include "ecosystems.h"

class Level_Generator
{
    typedef std::unique_ptr<Tiles::Tile> TilePtr;

    public:
        Level_Generator     ( Tile_Map& tiles, Game& game, const int seed = random::num ( 0, 100000) );

    private:
        void
        createIsland( const int x, const int y );

        void
        chooseEcosystem     ();

        const int
        ecosystemAt         ( const int x, const int y );

        void
        genGrassEcosystem   ( const int currX, const int currY );

        void
        genRockyEcosystem   ( const int currX, const int currY );

        void
        genOceonEcosystem   ( const int currX, const int currY );

        void
        genSnowyEcosystem   ( const int currX, const int currY );

        void
        testForNewEcosystem ( const int currX, const int currY );

    private:
        TilePtr
        addGrassTile        ( const int x, const int y );

        TilePtr
        addWaterTile        ( const int x, const int y );

        TilePtr
        addIceTile          ( const int x, const int y );

        TilePtr
        addCliffTile        ( const int x, const int y );

    private:
        const bool
        dotDistanceGood     ( const int x, const int y );

    private:
        Tile_Map*                   m_tileMap;
        Game*                       m_game;

        Ecosystem                   m_currEcosystem;

        const int                   EDGE_BOUNDS_X   { (int)ceil( Win_Info::WIDTH  / Tiles::Info::SIZE ) },
                                    EDGE_BOUNDS_Y   { (int)ceil( Win_Info::HEIGHT / Tiles::Info::SIZE ) },
                                    MAP_SIZE            { Tiles::Info::MAP_SIZE };

        std::vector<sf::IntRect>    m_islands;
        std::vector<Ecosystem>      m_ecosystemMap;
};

#endif // LEVELGEN_H
