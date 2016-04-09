#include "test.h"

#include "tile_types.h"

#include "rand.h"
#include "levelgen.h"

#include "zombie.h"
#include "shark.h"

#include <iostream>
#include <thread>

namespace State
{

Test :: Test  ( Game* game )
:   State_Base      ( game )
,   generator       ( m_tileMap, getGame() )
,   m_player        ( game, &m_tileMap )
{

}

void
Test :: input ( const double dt )
{
    m_player.input ( dt );
}

void
Test :: update ( const double dt )
{
    addMobs();

    m_player.update( dt );

    m_tileMap.update( dt,  m_player.getTileMapPosition() );


    for ( auto& mob : m_mobs ) mob->update ( dt );

    for ( unsigned i = 0; i < m_mobs.size() ; i++ )
    {
        m_mobs.at(i)->update( dt );
        if ( !m_mobs.at(i)->isAlive() )
        {
            m_mobs.erase(m_mobs.begin() + i );
        }
    }
}

void
Test :: glDraw ( const double dt )
{

}

void
Test :: sfDraw( const double dt )
{
    getGame().getWindow().pushGLStates();

    m_tileMap.draw ( getGame().getWindow().get(), m_player.getTileMapPosition() );
    m_player. draw ( getGame().getWindow().get() );

    for ( auto& mob : m_mobs ) mob->draw ( getGame().getWindow().get() );

    getGame().getWindow().popGLStates();
}

void
Test :: addMobs ()
{
    if ( timer.getElapsedTime().asSeconds() > 1.0f )
    {
        //if ( random::num( 1, 10) == 1)
        {
            addZombie   ();
            addShark    ();

        }
        timer.restart();
    }
}

void
Test :: addZombie ()
{
    m_mobs.emplace_back( std::make_unique<Zombie>( &getGame(), &m_tileMap, &m_player, &m_mobs ));
}

void
Test :: addShark ()
{
    m_mobs.emplace_back( std::make_unique<Shark>( &getGame(), &m_tileMap, &m_player ));
}


} //Namespace State
