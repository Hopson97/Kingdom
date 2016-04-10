#ifndef AI_COMPONENT_H
#define AI_COMPONENT_H

#include "component.h"
#include "enemy_mob.h"

namespace Component
{

class AI_Component : public Component_Base
{
    public:
        AI_Component ( Mob* mob )
        :   m_mob ( mob )
        { }

        virtual void
        logic   ( const float dt ) = 0;

    protected:
        const unsigned
        getDistanceTo       ( const sf::Vector2i& otherPos ) const;

        Mob*    m_mob;
};

}

#endif // AI_COMPONENT_H
