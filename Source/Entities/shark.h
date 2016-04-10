#ifndef SHARK_H
#define SHARK_H

#include "enemy_mob.h"


class Shark : public Enemy_Mob
{
    public:
        Shark( Game* game, Tile_Map* tiles, Player* player );

        void
        uniqueLogic( const float dt ) override;

    private:
};

#endif // SHARK_H
