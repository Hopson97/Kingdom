#ifndef PLAYER_H
#define PLAYER_H

#include "Bases/mob.h"

#include "../game.h"

class Player    :   public Mob
{
    public:
        Player              ( Game* game, Tile_Map* tiles );

        void
        input               ( const float dt );

    private:
        void
        uniqueLogic         ( const float dt ) override;

        void
        updateView          ();

        void
        setUpAnimation      ();


    private:
        sf::View            m_view;
        sf::RenderWindow*   m_window;

        //Animation           m_walkAnim;
};

#endif // PLAYER_H
