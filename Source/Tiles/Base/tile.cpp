#include "tile.h"

#include "../../Util/rand.h"
#include "../../Entities/Bases/sf_entity.h"

namespace Tiles
{

Tile :: Tile (  const Game& game, const sf::Vector2i& pos,
                const Ecosystem ecosystem, const sf::Color& light )
:   Sf_Entity       ( randomTexture( game ) )
,   m_tilePos       ( pos )
,   m_ecosystem     ( ecosystem )
,   m_light         ( light )
{
    m_sprite.setPosition    ( pos.x * Info::SIZE, pos.y * Info::SIZE );
}

void Tile :: update ( const float dt )
{

}

void Tile :: updateLight ( const std::vector<Light>& lights )
{
    //Start the lights as being dark
    m_light = { 0, 0, 0 };

    for ( const Light& light : lights)
    {
        if ( m_light.r < 255 &&
             m_light.g < 255 &&
             m_light.b < 255 )
        {
            //Increase the light of the tile based on distance from the light
            m_light += light.getLightFromIntensity ( m_tilePos );
        }
    }
    applyLight();
}

void Tile :: draw ( sf::RenderWindow& window)
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
    m_txrId = kingdom_random::num( 1, 3 );

    return getTexture( game, m_txrId );
}

const sf::Texture& Tile :: getTexture ( const Game& game, const unsigned id )
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

void Tile :: applyLight ()
{
    m_sprite.setColor( m_info.colour * m_light );
}

void Tile :: setInfo ( const Tile_Info& info)
{
    m_info = info;
    m_sprite.setColor( info.colour );
}

void Tile :: setColour ( const sf::Color& color )
{
    m_sprite.setColor( color );
}

bool Tile :: isWalkable () const
{
    return m_info.isWalkable;
}

bool Tile :: isSwimmable () const
{
    return m_info.isSwimmable;
}

const sf::Vector2i& Tile :: getTileMapPos () const
{
    return m_tilePos;
}

double Tile :: getFriction () const
{
    return m_info.friction;
}

double Tile :: getViscosity () const
{
    return m_info.viscosity;
}

Ecosystem Tile :: getEcosystem () const
{
    return m_ecosystem;
}

unsigned Tile :: getTxrId () const
{
    return m_txrId;
}

const sf::Color& Tile :: getLight () const
{
    return m_light;
}

} //namespace Tiles
