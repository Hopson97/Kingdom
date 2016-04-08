#include "ice.h"

#include "rand.h"
#include "water.h"

namespace Tiles
{

Ice :: Ice ( Game& game, const sf::Vector2i& pos, Tile_Map* tileMap, const Ecosystem ecosystem )
:   Tile        ( game, pos, Info::Colours::ice, ecosystem, true, false, 0.95 )
,   m_tileMap   ( tileMap )
,   m_game      ( &game )
{

}

void
Ice :: update  ( const float dt )
{
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
                                    ( *m_game, sf::Vector2i { getTileMapPos().x, getTileMapPos().y }, *m_tileMap, getEcosystem() );
}

} //namespace tiles
