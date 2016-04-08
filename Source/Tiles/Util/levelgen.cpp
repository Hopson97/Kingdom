#include "levelgen.h"

#include "rand.h"

#include <iostream>


/*
    For the to do list, it is probably possible to add an "ecosystem" using only a single method but rather defining
    each of their tiles types etc in a class or text file (and static enum casts )
*/

typedef std::unique_ptr<Tiles::Tile> TilePtr;

Level_Generator :: Level_Generator  ( Tile_Map& tiles, Game& game, const int seed )
{
    m_tileMap = &tiles;
    m_game = &game;

    //srand( seed );

    //Fill map with water
    for ( int currYTile = 0 ; currYTile < MAP_SIZE ; currYTile++ )
    {
        for ( int currXTile = 0; currXTile < MAP_SIZE ; currXTile++  )
        {
             m_tileMap->at( currXTile, currYTile) = addWaterTile( currXTile, currYTile );
        }
    }

    //Create islands
    const int ISLAND_ATTEMPTS = 795;
    while ( m_islands.size() < 5 )
    {
        for ( int i = 0 ; i < ISLAND_ATTEMPTS ; i++ )
        {
            int x = random::num( 0, MAP_SIZE ),
                y = random::num( 0, MAP_SIZE );

            createIsland( x, y);
        }
    }

    srand(time(NULL));

    m_islands.clear();
    m_ecosystemMap.clear();
}

void
Level_Generator :: createIsland( const int x, const int y )
{
    //The general width and height of the island
    int width   = random::num( 18, 40 ),
        height  = random::num( 18, 40 );

    sf::IntRect isle( x, y, width, height );

    if ( x < 10 ) return;
    if ( y < 10 ) return;

    if ( x + width >= MAP_SIZE - 10 ) return;
    if ( y + height >= MAP_SIZE - 10 ) return;

    m_islands.push_back( isle );

    m_currEcosystem = Ecosystem::Grassland;

    //Initial creation (square)
    for ( int xPos = x ; xPos < x + width ; xPos++ )
    {
        for ( int yPos = y ; yPos < y + height ; yPos++ )
        {
            m_tileMap->at( xPos, yPos) = addGrassTile( xPos, yPos);
        }
    }
}


void
Level_Generator :: chooseEcosystem ()
{
    int numEcosystems  = Ecosystem::NUM_ECOSYSTEMS - 1;

    m_currEcosystem = static_cast<Ecosystem>(random::num(0, numEcosystems ));
}

const int
Level_Generator :: ecosystemAt         ( const int x, const int y )
{
    return m_ecosystemMap.at( y * MAP_SIZE) + x;
}

void
Level_Generator :: genGrassEcosystem   ( const int currX, const int currY )
{
    addGrassTile    ( currX, currY );
}

void
Level_Generator :: genRockyEcosystem   ( const int currX, const int currY )
{
    addCliffTile    ( currX, currY );
}

void
Level_Generator :: genOceonEcosystem   ( const int currX, const int currY )
{
    addWaterTile    ( currX, currY );
}

void
Level_Generator :: genSnowyEcosystem   ( const int currX, const int currY )
{
    addIceTile      ( currX, currY );
}

void
Level_Generator :: testForNewEcosystem ( const int currX, const int currY )
{
    chooseEcosystem();
}

TilePtr
Level_Generator :: addGrassTile ( const int x, const int y )
{
    return std::make_unique<Tiles::Grass>
           ( *m_game, sf::Vector2i { x, y }, m_currEcosystem );
}

TilePtr
Level_Generator :: addWaterTile    ( const int x, const int y )
{
    return std::make_unique<Tiles::Water>
           ( *m_game, sf::Vector2i { x, y }, *m_tileMap, m_currEcosystem );
}

TilePtr
Level_Generator :: addIceTile      ( const int x, const int y )
{
    return std::make_unique<Tiles::Ice>
           ( *m_game, sf::Vector2i { x, y }, m_tileMap, m_currEcosystem  );
}

TilePtr
Level_Generator :: addCliffTile      ( const int x, const int y )
{
    return  std::make_unique<Tiles::Cliff>
            ( *m_game, sf::Vector2i { x, y }, m_currEcosystem );
}

