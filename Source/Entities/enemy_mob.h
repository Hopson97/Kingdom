#ifndef ENEMY_MOB_H
#define ENEMY_MOB_H

/*
    The entities that attack the player, thus have more things.
*/
#include "player.h"
#include "mob.h"


class Enemy_Mob  :  public Mob
{
    public:
        Enemy_Mob(  Game* game, const sf::Texture& texture, Tile_Map* tiles, Player* player  );

        virtual void
        uniqueLogic( const float dt ) = 0;

        void
        setTarget                   ( Mob* mob );

        const Mob*
        getTarget                   () const;

        const sf::Vector2i
        getTargetTilePosition       ();

        const bool
        hasTarget                   () const;

    protected:
        Player* player;

        Mob*    m_target            { nullptr };

        void
        attack();

};

#endif // ENEMY_MOB_H
