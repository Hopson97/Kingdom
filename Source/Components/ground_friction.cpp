#include "ground_friction.h"

namespace Component
{

Ground_Friction::Ground_Friction( Tile_Map* map, Mob* mob )
:   m_tileMap   ( map )
,   m_mob       ( mob )
{
}

void
Ground_Friction :: logic   ( const float dt )
{
    sf::Vector2i pos = m_mob->getTileMapPosition();

    if ( m_tileMap->at( pos )->isWalkable() )
    {
        m_mob->setVelocity( { (float)m_mob->getVelocity().x * (float)m_tileMap->getFriction( pos ),
                              (float)m_mob->getVelocity().y * (float)m_tileMap->getFriction( pos )
                            } );
    }
}

}
