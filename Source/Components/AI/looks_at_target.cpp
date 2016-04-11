#include "looks_at_target.h"

#include <cmath>
#include "maths.h"

namespace Component
{

Looks_At_Target :: Looks_At_Target ( Enemy_Mob* mob)
:   Component_Base  ( mob )
{
}

void
Looks_At_Target :: logic   ( const float dt )
{
    if ( m_mob->hasTarget() )
    {
        lookAtTarget();
    }
}

void
Looks_At_Target :: lookAtTarget ()
{
    //shorthand
    sf::Vector2f tPos = m_mob->getTarget()->getPosition();
    sf::Vector2f mPos = m_mob->getPosition();

    float dx = mPos.x - tPos.x;
    float dy = mPos.y - tPos.y;

    m_mob->setRotation( Math::getRot( dx, dy ) );
}

}
