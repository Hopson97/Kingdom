#include "tilemap.h"

#include <iostream>

#define SELF (*this)

typedef std::unique_ptr<Tiles::Tile> TilePtr;

Tile_Map :: Tile_Map()
{

}

TilePtr&
Tile_Map :: operator ()( const int x, const int y)
{
    return m_tiles.at( ( y * m_WIDTH ) + x );
}

TilePtr&
Tile_Map :: at ( const int x, const int y )
{
    return SELF( x, y);
}

TilePtr&
Tile_Map :: operator ()(  const sf::Vector2i& pos )
{
    return m_tiles.at( ( pos.y * m_WIDTH ) + pos.x );
}

TilePtr&
Tile_Map :: at ( const sf::Vector2i& pos )
{
    return SELF( pos.x, pos.y);
}

const double
Tile_Map :: getFriction ( const sf::Vector2i& pos )
{
    return at( pos )->getFriction();
}


void
Tile_Map :: update      ( const float dt, const sf::Vector2i& playerTilePos )
{

    const int tilesX = (Win_Info::WIDTH / Tiles::Info::SIZE) + 3;
    const int tilesY = (Win_Info::WIDTH / Tiles::Info::SIZE) + 3;

    int xStart = playerTilePos.x - tilesX;
    int xEnd = playerTilePos.x + tilesX;

    if ( xStart < 0 ) xStart = 0;
    if ( xEnd > Tiles::Info::MAP_SIZE - 1 ) xEnd = Tiles::Info::MAP_SIZE - 1;

    int yStart = playerTilePos.y - tilesY;
    int yEnd = playerTilePos.y + tilesY;

    if ( yStart < 0 ) yStart = 0;
    if ( yEnd > Tiles::Info::MAP_SIZE - 1 ) yEnd = Tiles::Info::MAP_SIZE - 1;

    for ( int y = yStart ; y < yEnd ; y++ )
    {
        for ( int x = xStart ; x < xEnd ; x++ )
        {
            this->at( x, y )->update ( dt );
        }
    }
}

void
Tile_Map :: draw ( sf::RenderWindow& window, const sf::Vector2i& playerTilePos )
{
    const int tilesX = (Win_Info::WIDTH / Tiles::Info::SIZE) + 3;
    const int tilesY = (Win_Info::WIDTH / Tiles::Info::SIZE) + 3;

    int xStart = playerTilePos.x - tilesX;
    int xEnd = playerTilePos.x + tilesX;

    if ( xStart < 0 ) xStart = 0;
    if ( xEnd > Tiles::Info::MAP_SIZE - 1 ) xEnd = Tiles::Info::MAP_SIZE - 1;

    int yStart = playerTilePos.y - tilesY;
    int yEnd = playerTilePos.y + tilesY;

    if ( yStart < 0 ) yStart = 0;
    if ( yEnd > Tiles::Info::MAP_SIZE - 1 ) yEnd = Tiles::Info::MAP_SIZE - 1;

    for ( int y = yStart ; y < yEnd ; y++ )
    {
        for ( int x = xStart ; x < xEnd ; x++ )
        {
            this->at( x, y )->draw ( window );
        }
    }
}

void
Tile_Map :: addTile ( TilePtr tile )
{
    m_tiles.push_back( std::move(tile) );
}

void
Tile_Map :: changeTile  ( TilePtr tile )
{
    at ( tile->getTileMapPos() ) = std::move(tile);
}
