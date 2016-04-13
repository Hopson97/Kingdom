#include "water.h"
#include "ice.h"

#include "rand.h"

namespace Tiles
{

Water :: Water ( Game& game, const sf::Vector2i& pos,  Tile_Map& tileMap,
                 const Ecosystem ecosystem, const sf::Color& light )
:   Tile        ( game, pos, ecosystem, light )
,   m_game      ( &game )
,   m_tileMap   ( &tileMap )
{
    setInfo( game.getTileInfo( TILE_WATER ) );

    applyLight();
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
    m_tileMap->at( getTileMapPos() ) = std::make_unique<Tiles::Ice>
                                    ( *m_game, getTileMapPos(), m_tileMap, getEcosystem(), getLight() );
}


} //namespace Tiles
