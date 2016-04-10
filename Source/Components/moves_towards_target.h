#ifndef MOVES_TOWARDS_TARGET_H
#define MOVES_TOWARDS_TARGET_H

/*
    Moves the mob towards the target given there is one.
*/

#include "enemy_mob.h"
#include "ai_component.h"

#include <vector>

namespace Component
{

class Moves_Towards_Target : public AI_Component
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
