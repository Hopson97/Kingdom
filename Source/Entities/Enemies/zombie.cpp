#include "zombie.h"
#include "../../Components/AI/Aggressive_Targeting.h"
#include "../../Components/AI/looks_at_target.h"
#include "../../Components/AI/moves_towards_target.h"
#include "ground_friction.h"
#include "tile_collidable.h"
#include "swimmable.h"
#include "steps_on_tiles.h"
#include "spawns_ground.h"
#include "effected_by_light.h"

Zombie :: Zombie( Game* game, Tile_Map* tiles, Player* player, MobPtrVec* mobVec  )
:   Enemy_Mob   ( game, game->getTexture(TXR_ENT_ZOMBIE ), tiles, player )
{
    centerSpriteOrigin();

    addComponent( std::make_unique<Component::Spawns_Ground>
                ( this, tiles, player, 10, 30 ) );

    addComponent( std::make_unique<Component::Aggressive_Targeting>
                ( this, player, mobVec, 15 ) );

    addComponent( std::make_unique<Component::Looks_At_Target>
                ( this ) );

    addComponent( std::make_unique<Component::Moves_Towards_Target>
                ( this, 3 ) );

    addComponent( std::make_unique<Component::Ground_Friction>
                ( this, tiles ) );

    addComponent( std::make_unique<Component::Steps_On_Tiles>
                ( this, tiles ) );


    addComponent( std::make_unique<Component::Tile_Collidable>
                ( this, tiles ) );

    addComponent( std::make_unique<Component::Effected_By_Light>
                ( this, tiles ) );

    m_walkSpeed = 20;
}

void
Zombie :: uniqueLogic         ( const float dt )
{

}
