// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
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

//For variation, a random texture is chosen.
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

const bool
Tile :: isWalkable      () const
{
    return m_info.isWalkable;
}

const bool
Tile :: isSwimmable     () const
{
    return m_info.isSwimmable;
}

const sf::Vector2i&
Tile :: getTileMapPos   () const
{
    return m_tilePos;
}

const double
Tile :: getFriction     () const
{
    return m_info.friction;
}

const double
Tile :: getViscosity    () const
{
    return m_info.viscosity;
}

const Ecosystem
Tile :: getEcosystem    () const
{
    return m_ecosystem;
}

const unsigned
Tile :: getTxrId                () const
{
    return m_txrId;
}























} //namespace Tiles
