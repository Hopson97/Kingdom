#ifndef ENEMY_MOB_H
#define ENEMY_MOB_H

/*
    The entities that attack the player, thus have more things.
*/
#include "../../Entities/player.h"
#include "../../Entities/Bases/enemy_mob.h"


class Enemy_Mob  :  public Mob
{
public:

        virtual void uniqueLogic( const float dt ) = 0;

    protected:
        Enemy_Mob(  Game* game, const sf::Texture& texture, Tile_Map* tiles, Player* player  );

        Player* player;

        virtual void
        attack() = 0;

};

#endif // ENEMY_MOB_H
