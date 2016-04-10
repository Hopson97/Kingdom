#include "moves_towards_target.h"

#include <cmath>
#include "maths.h"

namespace Component
{

Moves_Towards_Target :: Moves_Towards_Target ( Enemy_Mob* mob)
:   m_mob               ( mob )
{
}

void
Moves_Towards_Target :: logic   ( const float dt )
{
    if ( m_mob->hasTarget() )
    {
        move ( dt );
    }
}

void
Moves_Towards_Target :: move ( const float dt )
{
    m_mob->velocityForwards( dt )
}

}
