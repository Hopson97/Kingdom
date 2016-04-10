#include "moves_towards_target.h"

#include <cmath>
#include "maths.h"

namespace Component
{

Moves_Towards_Target :: Moves_Towards_Target ( Mob* mob, unsigned distBeforeStop)
:   AI_Component        ( mob )
,   m_distBeforeStop    ( distBeforeStop)
{
}

void
Moves_Towards_Target :: logic   ( const float dt )
{
    if ( m_mob->hasTarget() )
    {
        //If the distance is greater than the maximum distance before stopping.
        if ( getDistanceTo( m_mob->getTargetTilePosition() ) > m_distBeforeStop )
        {
            m_mob->velocityForwards( dt );
        }
        else
        {
            m_mob->velocityBackwards( dt );
        }
    }
}



}
