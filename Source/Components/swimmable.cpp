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

    if ( m_tileMap->at( pos )->isSwimmable() ) m_mob->setMobState( MOB_STATE_WATER );
    else
    {
        if ( m_canLand) m_mob->setMobState( MOB_STATE_GROUND );
    }
}

}
