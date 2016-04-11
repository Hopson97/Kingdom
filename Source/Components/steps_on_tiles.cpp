#include "steps_on_tiles.h"

namespace Component
{

Steps_On_Tiles :: Steps_On_Tiles( Mob* mob, Tile_Map* tileMap )
:   Component_Base       ( mob )
,   m_tileMap           ( tileMap )
,   m_mobsCurrTilePos   ( mob->getTileMapPosition() )
{

}

void
Steps_On_Tiles :: logic ( const float dt )
{
    //Calls the "steppedOn" method from the tile class
    if ( m_mobsCurrTilePos != m_mob->getTileMapPosition() )
    {
        m_tileMap->at( m_mob->getTileMapPosition() )->steppedOn();
        m_mobsCurrTilePos == m_mob->getTileMapPosition();
    }
}

} // Namespace component
