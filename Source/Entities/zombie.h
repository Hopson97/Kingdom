#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "mob.h"
#include "player.h"

class Zombie : public Mob
{
    public:
        Zombie( Game* game, Tile_Map* tiles, Player& player );

    protected:
        void
        uniqueLogic         ( const float dt ) override;

    private:
        Player* m_player;
};

#endif // ZOMBIE_H
