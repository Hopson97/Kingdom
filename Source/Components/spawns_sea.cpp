#include "spawns_sea.h"

#include "rand.h"

#include <cmath>

/*
    Spawns the mob within a radius of the player.

    De-spawns when outside "distToDespawn" radius.
*/

namespace Component
{

Spawns_Sea :: Spawns_Sea( Mob* mob, Tile_Map* tiles, Player* player,
                                        const int maxDistFromPlayer, const int distToDespawn )
:  Component_Base   ( mob )
,   m_player        ( player )
,   m_tiles         ( tiles )
,   m_distToDespawn ( distToDespawn )
{
   spawn( maxDistFromPlayer );
}

void
Spawns_Sea :: spawn ( const int maxDistFromPlayer )
{
    //Check for where the possible spawning checks starts from
    int x = m_player->getTileMapPosition().x - maxDistFromPlayer;
    if ( x <= 0 ) x = 1;

    int y = m_player->getTileMapPosition().y - maxDistFromPlayer;
    if ( y <= 0 ) y = 1;

    //Check for where the possible spawning checks ends
    int xBound = x + maxDistFromPlayer * 2;
    int yBound = y + maxDistFromPlayer * 2;

    if ( xBound >= Tiles::Info::MAP_SIZE ) xBound = Tiles::Info::MAP_SIZE - 1;
    if ( yBound >= Tiles::Info::MAP_SIZE ) yBound = Tiles::Info::MAP_SIZE - 1;

    m_hasSpawned = false;
    for ( int i = 0; i < 10 ; i++ )
    {
        int xPos = random::num( x, xBound );
        int yPos = random::num( y, yBound );

        if ( m_tiles->at( xPos, yPos )->isSwimmable() )
        {
            m_mob->setPosition( { ( float ) xPos * Tiles::Info::SIZE,
                                  ( float ) yPos * Tiles::Info::SIZE
                                } );
            m_hasSpawned = true;
            break;

        }
    }
    if ( !m_hasSpawned )
    {
        m_mob->setAlive( false );
    }
    else
    {
        m_mob->setAlive( true );
    }
}



void
Spawns_Sea :: logic ( const float dt )
{
    checkDist();


}

void
Spawns_Sea :: getTarget ()
{

}

void
Spawns_Sea :: checkDist   ()
{
    int dy = abs ( m_player->getTileMapPosition().y - m_mob->getTileMapPosition().y );
    int dx = abs ( m_player->getTileMapPosition().x - m_mob->getTileMapPosition().x );

    int length = sqrt( (dy * dy ) + (dx * dx ) );

    if ( length > m_distToDespawn )
    {
        m_mob->setAlive( false );
    }
}

} // Namespace component
