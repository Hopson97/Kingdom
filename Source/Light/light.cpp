#include "light.h"

#include "../Util/maths.h"

bool Light :: m_lightUpdateNeeded = true;

Light :: Light ( const sf::Vector2i& tileLocation, const unsigned intensity )
:   m_tileLocation      ( tileLocation )
,   m_intensity         ( intensity )
{
    m_lightUpdateNeeded = true;
}

void Light :: setTileLocation ( const sf::Vector2i& tileLocation )
{
    if ( tileLocation != m_tileLocation )
    {
        m_lightUpdateNeeded = true;
        m_tileLocation = tileLocation;
    }
}

unsigned Light :: getIntensity   () const
{
    return m_intensity;
}

const sf::Vector2i Light :: getLocation    () const
{
    return m_tileLocation;
}

bool Light :: isLightUpdate  () const
{
    return m_lightUpdateNeeded;
}

void Light :: turnOffLightUpdate ()
{
    m_lightUpdateNeeded = false;
}

const sf::Color Light :: getLightFromIntensity ( const sf::Vector2i& tileMapPos ) const
{
    auto dist = Math::getDistance<unsigned>( m_tileLocation, tileMapPos );

    if ( dist > m_intensity )
    {
        return { 0, 0, 0};
    }

    if ( dist == 0 ) dist = 1;



    sf::Uint8 light = 255 / dist;

    return { light, light, light };
}

