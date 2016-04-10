#ifndef GROUND_FRICTION_H
#define GROUND_FRICTION_H

#include "Other/tilemap.h"
#include "Bases/mob.h"
#include "Bases/component.h"

/*
    Applies friction to mobs based on tiles friction values.
*/

namespace Component
{

class Ground_Friction : public Component_Base
{
    public:
        Ground_Friction( Tile_Map* map, Mob* mob );

        void
        logic   ( const float dt ) override;

    private:
        Tile_Map*   m_tileMap;
        Mob*        m_mob;
};

}

#endif // GROUND_FRICTION_H
