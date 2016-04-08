#include "shark.h"

#include "spawns_sea.h"

Shark :: Shark( Game* game, Tile_Map* tiles, Player& player )
:   Mob ( game, game->getTexture ( TXR_ENT_WHALE), tiles )
{
    addComponent( std::make_unique<Component::Spawns_Sea>
                ( this, tiles, &player, 5, 30 ) );
}

void
Shark :: uniqueLogic( const float dt )
{

}
