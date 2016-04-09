#include "enemy_mob.h"

Enemy_Mob :: Enemy_Mob(  Game* game, const sf::Texture& texture, Tile_Map* tiles, Player* player  )
:   Mob ( game, texture, tiles )
{

}

void
Enemy_Mob :: setTarget   ( Mob* mob )
{
    m_target = mob;
}

void
Enemy_Mob :: attack()
{

}

const Mob*
Enemy_Mob :: getTarget    () const
{
    return ( m_target ) ? m_target : nullptr;
}

const sf::Vector2i
Enemy_Mob :: getTargetTilePosition    ()
{
    return ( m_target ) ? m_target->getTileMapPosition() : sf::Vector2i( 0, 0 );
}

const bool
Enemy_Mob :: hasTarget () const
{
    return ( m_target ) ? true : false;
}
