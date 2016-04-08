#include "water.h"

#include "rand.h"

#include <iostream>

namespace Tiles
{

Water :: Water ( Game& game, const sf::Vector2i& pos,  Tile_Map& tileMap, const Ecosystem ecosystem  )
:   Tile        ( game, pos, Info::Colours::sea, ecosystem, false, true, 1, 0.7 )
,   m_game      ( &game )
,   m_tileMap   ( &tileMap )
{

}

void
Water :: update ( const float dt )
{
    if ( !inWindowBounds( m_game->getWindow().get() ) ) return;



    if ( m_txrClock.getElapsedTime().asSeconds() > (float)random::num( 5, 10 ) / 10.0f  )
    {
        unsigned newId = getTxrId();
        while ( newId == getTxrId() )
        {
            newId = random::num( 1, 3 );
        }

        m_sprite.setTexture( getTexture ( *m_game, newId ) );
        m_txrClock.restart();
    }
}

void
Water :: steppedOn ()
{

}


} //namespace Tiles
