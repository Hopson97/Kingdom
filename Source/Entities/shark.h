#ifndef SHARK_H
#define SHARK_H

#include "mob.h"
#include "player.h"

class Shark : public Mob
{
    public:
        Shark( Game* game, Tile_Map* tiles, Player& player );

        void
        uniqueLogic( const float dt ) override;

    protected:

    private:
};

#endif // SHARK_H
