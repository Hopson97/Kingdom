#include "swimmable.h"

namespace Component
{

Swimmable :: Swimmable ( Mob* mob, Tile_Map* map, const bool canLand, Game& game )
:   m_tileMap   ( map )
,   m_mob       ( mob )
,   m_canLand   ( canLand )
,   m_window    ( &game.getWindow().get() )
,   m_splash    ( 100, sf::seconds( 1 ), sf::Color::White )
{ }

void
Swimmable :: logic   ( const float dt )
{
    sf::Vector2i pos = m_mob->getTileMapPosition();

    m_splash.update ( sf::seconds( dt ) );
    m_splash.draw   ( *m_window );
    m_splash.setEmitter( m_mob->getPosition() );

    if ( m_tileMap->at( pos )->isSwimmable() )
    {
        m_mob->setMobState( MOB_STATE_WATER );
        m_mob->setVelocity( { (float)m_mob->getVelocity().x * (float)m_tileMap->getViscosityAt( pos ),
                              (float)m_mob->getVelocity().y * (float)m_tileMap->getViscosityAt( pos )
                            } );

        //Draws the splash particles only if the player has moved
        //if ( m_prevMobPos != m_mob->getPosition() )
        {
            m_splash.setEmitter( m_mob->getPosition() );
            m_splash.setUpdate( true );
            m_prevMobPos = m_mob->getPosition();
            return;
        }
    }
    else
    {
        if ( m_canLand) m_mob->setMobState( MOB_STATE_GROUND );
    }
    m_splash.setUpdate( false );
}

}
