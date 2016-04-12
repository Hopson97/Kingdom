#include "ice.h"

#include "rand.h"
#include "water.h"

namespace Tiles
{

Ice :: Ice ( Game& game, const sf::Vector2i& pos, Tile_Map* tileMap,
             const Ecosystem ecosystem, const sf::Color& light )
:   Tile        ( game, pos, ecosystem, light  )
,   m_tileMap   ( tileMap )
,   m_game      ( &game )
{
    setInfo( game.getTileInfo( TILE_ICE ) );

    applyLight();
}

void
Ice :: update  ( const float dt,  const std::vector<Light>& lights )
{
    Tile::update( dt, lights );

    if ( m_meltTimer.getElapsedTime().asSeconds() > 5.0f && getEcosystem() != Ecosystem::Snowy )
    {
        if ( random::num( 1, 3) == 1 )
        {
            melt();

        }
        m_meltTimer.restart();
    }
}

void
Ice :: melt()
{
    m_tileMap->at( getTileMapPos() ) = std::make_unique<Tiles::Water>
                                    ( *m_game, sf::Vector2i { getTileMapPos().x, getTileMapPos().y }, *m_tileMap, getEcosystem(), getLight() );
}

void
Ice :: steppedOn ()
{
    m_meltTimer.restart();
}

} //namespace tiles
