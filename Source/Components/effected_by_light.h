#ifndef EFFECTED_BY_LIGHT_H
#define EFFECTED_BY_LIGHT_H

#include "Other/tilemap.h"
#include "Bases/mob.h"

#include "Bases/component.h"

namespace Component
{

class Effected_By_Light : public Component_Base
{
    public:
        Effected_By_Light( Mob* mob, Tile_Map* tiles);

        void
        logic   ( const float dt ) override;

    protected:

    private:
        Tile_Map* m_tiles;
};

}

#endif // EFFECTED_BY_LIGHT_H
