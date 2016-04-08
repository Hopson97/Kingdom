#ifndef SWIMMABLE_H
#define SWIMMABLE_H

#include "tilemap.h"
#include "mob.h"
#include "component.h"

namespace Component
{

class Swimmable : public Component_Base
{
    public:
        Swimmable ( Tile_Map* map, Mob* mob, const bool canLand );

        void
        logic   ( const float dt ) override;

    private:
        Tile_Map*   m_tileMap;
        Mob*        m_mob;

        const bool  m_canLand;
};

}

#endif // SWIMMABLE_H
