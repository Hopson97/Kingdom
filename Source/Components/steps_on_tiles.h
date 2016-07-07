#ifndef STEPS_ON_TILES_H
#define STEPS_ON_TILES_H

#include "../Tiles/Other/tilemap.h"

#include "../Entities/Bases/mob.h"

#include "Bases/component.h"

/*
    Every time the mob steps on a new tile, it calls the "steppedOn()" method for that tile
*/

namespace Component
{

class Steps_On_Tiles : public Component_Base
{
    public:
        Steps_On_Tiles( Mob* mob, Tile_Map* tile_map );

        void
        logic ( const float dt ) override;

    private:
        Tile_Map*       m_tileMap;

        sf::Vector2i    m_mobsCurrTilePos;
};

} // Namespace component

#endif // STEPS_ON_TILES_H
