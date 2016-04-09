#include "Aggressive_Targeting.h"

#include <iostream>
#include <cmath>

namespace Component
{

Aggressive_Targeting :: Aggressive_Targeting ( Enemy_Mob* mob, Player* player,
    MobPtrVec* mobs, unsigned maxDist )
:   m_mob               ( mob )
,   m_mobVec            ( mobs )
,   m_maxDist           ( maxDist )
,   m_player            ( player )
{
}

void
Aggressive_Targeting :: logic   ( const float dt )
{
    checkDistToPlayer   ();
    checkTarget         ();
}

void
Aggressive_Targeting :: checkDistToPlayer ()
{
    if ( !m_mob->getTarget() )
    {
        if ( getDistance( m_player->getTileMapPosition() ) <= m_maxDist )
        {
            m_mob->setTarget ( m_player );
        }
    }
}

void
Aggressive_Targeting :: checkTarget ()
{
    if ( getDistance( m_mob->getTargetTilePosition() ) > m_maxDist && m_mob->getTarget() )
    {
        m_mob->setTarget ( nullptr );
    }
}

const unsigned
Aggressive_Targeting :: getDistance ( const sf::Vector2i& otherPos ) const
{
    int dy = abs ( otherPos.y - m_mob->getTileMapPosition().y );
    int dx = abs ( otherPos.x - m_mob->getTileMapPosition().x );

    return  sqrt( pow ( dx, 2 ) + pow ( dy, 2 ) );
}

}
