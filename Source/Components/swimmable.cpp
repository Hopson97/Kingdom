#include "swimmable.h"

namespace Component
{


Swimmable :: Swimmable ( Tile_Map* map, Mob* mob, const bool canLand )
:   m_tileMap   ( map )
,   m_mob       ( mob )
,   m_canLand   ( canLand )
{
}

void
Swimmable :: logic   ( const float dt )
{
    sf::Vector2i pos = m_mob->getTileMapPosition();

    if ( m_tileMap->at( pos )->isSwimmable() )
    {
        m_mob->setMobState( MOB_STATE_WATER );
        m_mob->setVelocity( { (float)m_mob->getVelocity().x * (float)m_tileMap->getViscosityAt( pos ),
                              (float)m_mob->getVelocity().y * (float)m_tileMap->getViscosityAt( pos )
                            } );
    }
    else
    {
        if ( m_canLand) m_mob->setMobState( MOB_STATE_GROUND );
    }
}

}
