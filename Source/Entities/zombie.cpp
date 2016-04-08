#include "zombie.h"

#include <iostream>

#include "Spawns_Ground.h"

Zombie :: Zombie( Game* game, Tile_Map* tiles, Player& player )
:   Mob         ( game, game->getTexture(TXR_ENT_ZOMBIE ), tiles )
,   m_player    ( &player )
{
    addComponent( std::make_unique<Component::Spawns_Ground>
                ( this, tiles, &player, 5, 20 ) );
}

void
Zombie :: uniqueLogic         ( const float dt )
{

}
