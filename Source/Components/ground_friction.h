#ifndef GROUND_FRICTION_H
#define GROUND_FRICTION_H

#include "tilemap.h"
#include "mob.h"
#include "component.h"

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
