#ifndef SWIMMABLE_H
#define SWIMMABLE_H

#include "../Tiles/Other/tilemap.h"

#include "../Entities/Bases/enemy_mob.h"

#include "../Util/particle_system.h"

#include "Bases/component.h"

namespace Component
{

class Swimmable : public Component_Base
{
    public:
        Swimmable ( Mob* mob, Tile_Map* map, const bool canLand, Game& game );

        void
        logic   ( const float dt ) override;

    private:
        Tile_Map*           m_tileMap;

        const bool          m_canLand;

        sf::RenderWindow*   m_window;

        Particle_System     m_splash    { 100, sf::seconds( 1 ), sf::Color::White  };

        sf::Vector2f        m_prevMobPos;


};

}

#endif // SWIMMABLE_H
