// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#include "zombie.h"

#include <iostream>

#include "spawns_ground.h"
#include "Aggressive_Targeting.h"
#include "looks_at_target.h"
#include "moves_towards_target.h"

Zombie :: Zombie( Game* game, Tile_Map* tiles, Player* player, MobPtrVec* mobVec  )
:   Enemy_Mob   ( game, game->getTexture(TXR_ENT_ZOMBIE ), tiles, player )
{
    centerSpriteOrigin();

    addComponent( std::make_unique<Component::Spawns_Ground>
                ( this, tiles, player, 5, 20 ) );

    addComponent( std::make_unique<Component::Aggressive_Targeting>
                ( this, player, mobVec, 5 ) );

    addComponent( std::make_unique<Component::Looks_At_Target>
                ( this ) );
    addComponent( std::make_unique<Component::Moves_Towards_Target>
                ( this ) );
}

void
Zombie :: uniqueLogic         ( const float dt )
{

}
