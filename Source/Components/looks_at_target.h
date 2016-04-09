#ifndef LOOKS_AT_TARGET_H
#define LOOKS_AT_TARGET_H



#include "enemy_mob.h"
#include "component.h"

#include <vector>

namespace Component
{

class Looks_At_Target : public Component_Base
{
    public:
        explicit
        Looks_At_Target   ( Enemy_Mob* mob );

        void
        logic   ( const float dt ) override;

    private:
        void
        lookAtTarget ();


    private:
        Enemy_Mob*  m_mob;              //The mob to be controlling
};

}

#endif // LOOKS_AT_TARGET_H
