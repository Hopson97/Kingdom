#include "tilemap.h"

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
Tile_Map :: getFrictionAt ( const sf::Vector2i& pos )
{
    return at( pos )->getFriction();
}

const double
Tile_Map :: getViscosityAt ( const sf::Vector2i& pos )
{
    return at( pos )->getViscosity();
}


void
Tile_Map :: update ( const float dt, const sf::Vector2i& playerTilePos,
                     std::vector<Light>& lights )
{
    int xStart, yStart, xEnd, yEnd;
    getScreenBounds( xStart, yStart, xEnd, yEnd, playerTilePos );

    for ( int y = yStart ; y < yEnd ; y++ )
    {
        for ( int x = xStart ; x < xEnd ; x++ )
        {
            this->at( x, y )->update ( dt );

            if ( lightUpdateNeeded( lights ) )
            {
                this->at( x, y)->updateLight ( lights );
            }
        }
    }
    if ( !lights.empty() )
    {
        lights.at( 0 ).turnOffLightUpdate( );
    }
}

const bool
Tile_Map :: lightUpdateNeeded( const std::vector<Light>& lights ) const
{
    if ( !lights.empty() )
    {
        return ( lights.at( 0 ).isLightUpdate() );
    }
    return false;
}

void
Tile_Map :: draw ( sf::RenderWindow& window, const sf::Vector2i& playerTilePos )
{
    int xStart, yStart, xEnd, yEnd;
    getScreenBounds( xStart, yStart, xEnd, yEnd, playerTilePos );

    for ( int y = yStart ; y < yEnd ; y++ )
    {
        for ( int x = xStart ; x < xEnd ; x++ )
        {
            this->at( x, y )->draw ( window );
        }
    }
}

void
Tile_Map :: getScreenBounds(  int& xStart, int& yStart,
                              int& xEnd,   int& yEnd,
                              const sf::Vector2i& playerTilePos ) const
{
    constexpr static int tilesX = (Win_Info::WIDTH / Tiles::Info::SIZE);
    constexpr static int tilesY = (Win_Info::WIDTH / Tiles::Info::SIZE);

    xStart = playerTilePos.x - tilesX;
    yStart = playerTilePos.y - tilesY;

    if ( xStart < 0 ) xStart = 0;
    if ( yStart < 0 ) yStart = 0;

    xEnd = playerTilePos.x + tilesX;
    yEnd = playerTilePos.y + tilesY;

    if ( xEnd > Tiles::Info::MAP_SIZE - 1 ) xEnd = Tiles::Info::MAP_SIZE;
    if ( yEnd > Tiles::Info::MAP_SIZE - 1 ) yEnd = Tiles::Info::MAP_SIZE;
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
