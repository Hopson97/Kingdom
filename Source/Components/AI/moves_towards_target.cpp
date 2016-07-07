#include "moves_towards_target.h"

#include <cmath>
#include "../../Util/maths.h"

namespace Component
{

Moves_Towards_Target :: Moves_Towards_Target ( Mob* mob, unsigned distBeforeStop)
:   Component_Base       ( mob )
,   m_distBeforeStop    ( distBeforeStop)
{
}

void Moves_Towards_Target :: logic   ( const float dt )
{
    if ( m_mob->hasTarget() )
    {
        //If the distance is greater than the maximum distance before stopping.
        if ( Math::getDistance<unsigned>(m_mob->getTargetTilePosition(),
                                         m_mob->getTileMapPosition() )
           )
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
