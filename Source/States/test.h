#ifndef TEST_H
#define TEST_H

#include "game.h"
#include "Other/tilemap.h"
#include "player.h"
#include "Enemies/zombie.h"

#include "levelgen.h"

namespace State
{

class Test : public State_Base
{
    public:
        Test    ( Game* game);

        ~Test   () {}

        void
        input   ( const double dt ) override;

        void
        update  ( const double dt ) override;

        void
        glDraw  ( const double dt ) override;

        void
        sfDraw  ( const double dt ) override;

    private:
        void
        addMobs ();

        void
        addZombie ();

        void
        addShark ();

    private:
        Tile_Map            m_tileMap;

        Level_Generator     generator;

        Player              m_player;

        sf::Clock           timer;

        std::vector < std::unique_ptr<Mob> > m_mobs;

        std::vector <Light> m_lights;

};

}

#endif // TEST_H
