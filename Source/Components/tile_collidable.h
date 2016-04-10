#ifndef TILE_COLLIDABLE_H
#define TILE_COLLIDABLE_H

#include "Bases/component.h"
#include "tilemap.h"
#include "Bases/mob.h"

/*
    Does not allow the mob to walk into tiles marked as "not walkable"
*/

namespace Component
{

class Tile_Collidable : public Component_Base
{
    public:
        Tile_Collidable ( Tile_Map* tiles, Mob* mob );

        void
        logic ( const float dt ) override;

    private:
        void
        tileCollisionsXGround ();

        void
        tileCollisionsYGround ();

        void
        tileCollisionsXWater ();

        void
        tileCollisionsYWater ();

        void
        invertVelocity  ();

        void
        updatePrevTile  ();

        Tile_Map*       m_tileMap;
        Mob*            m_mob;

        bool            m_velInverted       { false };
        bool            m_isInBadTile       { false };

        sf::Vector2f    m_prevTileMapPos;


};

} //Namespace Component

#endif // TILE_COLLIDABLE_H
