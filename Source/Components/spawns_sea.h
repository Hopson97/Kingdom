#ifndef SPAWNS_SEA_H
#define SPAWNS_SEA_H

#include "Bases/component.h"

#include "../Entities/Bases/mob.h"
#include "../Entities/player.h"

#include "../Tiles/Other/tilemap.h"


namespace Component
{

class Spawns_Sea : public Component_Base
{
    public:
        Spawns_Sea ( Mob* mob, Tile_Map* tiles, Player* player,
                    const int maxDistFromPlayer, const int distToDespawn  );

        void logic ( const float dt ) override;

    private:
        void getTarget   ();

        void checkDist   ();

        void spawn       ( const int maxDistFromPlayer );

		
        Player*     m_player;
        Tile_Map*   m_tiles;
        Mob*        m_target;

        bool        m_hasSpawned;

        const int   m_distToDespawn;  //How far from the player before de-spawning
};

} // Namespace component

#endif // SPAWNS_SEA_H
