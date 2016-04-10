#ifndef MOVES_TOWARDS_TARGET_H
#define MOVES_TOWARDS_TARGET_H

#include "enemy_mob.h"
#include "component.h"

#include <vector>

namespace Component
{

class Moves_Towards_Target : public Component_Base
{
    public:
        explicit
        Moves_Towards_Target   ( Enemy_Mob* mob );

        void
        logic   ( const float dt ) override;

    private:
        void
        move ( const float dt );


    private:
        Enemy_Mob*  m_mob;              //The mob to be controlling
};

}

#endif // MOVES_TOWARDS_TARGET_H
