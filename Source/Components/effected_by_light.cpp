#include "effected_by_light.h"

namespace Component
{

Effected_By_Light :: Effected_By_Light( Mob* mob, Tile_Map* tiles )
:   Component_Base  ( mob )
,   m_tiles         ( tiles )
{
}

void Effected_By_Light :: logic   ( const float dt )
{
    m_mob->setColor( m_tiles->at( m_mob->getTileMapPosition() )->getLight() );
}

}
