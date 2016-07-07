#ifndef SHARK_H
#define SHARK_H

#include "../Bases/enemy_mob.h"


class Shark : public Enemy_Mob
{
    public:
        Shark				( Game* game, Tile_Map* tiles, Player* player );

        void attack			() override { }

    private:
        void uniqueLogic	( const float dt ) override;
};

#endif // SHARK_H
