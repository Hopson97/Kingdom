#include "light.h"

#include "maths.h"

Light :: Light ( const sf::Vector2i& tileLocation, const unsigned intensity )
:   m_tileLocation  ( tileLocation )
,   m_intensity     ( intensity )
{ }

void
Light :: setTileLocation ( const sf::Vector2i& tileLocation )
{
    m_tileLocation = tileLocation;
}

const unsigned
Light :: getIntensity    () const
{
    return m_intensity;
}

const sf::Vector2i
Light :: getLocation     () const
{
    return m_tileLocation;
}

const sf::Color
Light :: getLightFromIntensity   ( const sf::Vector2i& tileMapPos ) const
{
    unsigned dist = Math::getDistance<unsigned>( m_tileLocation, tileMapPos );

    if ( dist > m_intensity )
    {
        return { 0, 0, 0};
    }

    if ( dist == 0 ) dist = 1;
    if ( dist > 255 ) return { 255, 255, 255 };

    sf::Uint8 light = 255 / dist;

    return { light, light, light };

}

