#include "tile.h"

#include <iostream>

#include "rand.h"
#include "sf_entity.h"
namespace Tiles
{

Tile :: Tile (  const Game& game, const sf::Vector2i& pos, const Ecosystem ecosystem )
:   Sf_Entity       ( randomTexture( game ) )
,   m_tilePos       ( pos )
,   m_ecosystem     ( ecosystem )
{
    m_sprite.setPosition    ( pos.x * Info::SIZE, pos.y * Info::SIZE );
}

void
Tile :: draw ( sf::RenderWindow& window)
{
    if ( inWindowBounds( window ) )
    {
        window.draw ( m_sprite );
    }
}

const sf::Texture&
Tile :: randomTexture ( const Game& game )
{
    m_txrId = random::num( 1, 3 );

    return getTexture( game, m_txrId );
}

const sf::Texture&
Tile :: getTexture ( const Game& game, const unsigned id )
{
    m_txrId = id;

    switch ( m_txrId )
    {
    case 1:
        return game.getTexture( TXR_TILE );
    case 2:
        return game.getTexture( TXR_TILE2 );
    case 3:
        return game.getTexture( TXR_TILE3 );
    default:
        throw std::runtime_error ( "Unable to get texture ");
    }
}

void
Tile :: setInfo ( const Tile_Info& info)
{
    m_info = info;
    m_sprite.setColor( info.colour );
}

} //namespace Tiles
