#ifndef MOVES_TOWARDS_TARGET_H
#define MOVES_TOWARDS_TARGET_H

/*
    Moves the mob towards the target given there is one.
*/

#include "Bases/enemy_mob.h"
#include "Bases/component.h"

#include <vector>

namespace Component
{

class Moves_Towards_Target : public Component_Base
{
    public:
        Moves_Towards_Target   ( Mob* mob, unsigned distBeforeStop );

        void
        logic   ( const float dt ) override;

    private:
        unsigned    m_distBeforeStop;   //How far from the target does this move before it stops.



};

}

#endif // MOVES_TOWARDS_TARGET_H
