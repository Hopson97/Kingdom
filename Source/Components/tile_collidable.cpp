// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#include "tile_collidable.h"

#include <iostream>

namespace Component
{

Tile_Collidable :: Tile_Collidable( Mob* mob, Tile_Map* tiles )
    :   m_tileMap           ( tiles )
    ,   m_mob               ( mob )
{

}

void
Tile_Collidable :: logic ( const float dt )
{
    if ( m_isInBadTile)
    {
        m_mob->setPosition( m_prevTileMapPos );
    }

    m_velInverted = false;
    if ( m_mob->getMobState() == MOB_STATE_GROUND )
    {
        tileCollisionsXGround();
        tileCollisionsYGround();
    }
    else if ( m_mob->getMobState() == MOB_STATE_WATER )
    {
        tileCollisionsXWater();
        tileCollisionsYWater();
    }

    updatePrevTile();
}

void
Tile_Collidable :: tileCollisionsXGround ()
{
    auto walkable = [&]  ( int x, int y )
    {
        return
            m_tileMap->at( x, y )->isWalkable() ;
    };

    const float         vel = m_mob->getVelocity().x;
    const sf::Vector2i  pos = m_mob->getTileMapPosition();

    if ( vel > 0 )  //Check tiles right
    {
        if ( !( walkable( ( vel / Tiles::Info::SIZE ) +
                          pos.x,
                          pos.y ) ) )
        {
            invertVelocity( );
            return;
        }
    }
    else if ( vel < 0 ) //Check tiles left
    {
        if ( !( walkable( pos.x -
                          ( vel / Tiles::Info::SIZE ),
                          pos.y ) )
           )
        {
            invertVelocity( );
            return;
        }
    }
    m_isInBadTile = false;
}

void
Tile_Collidable :: tileCollisionsYGround ()
{
    auto walkable = [&]  ( int x, int y )
    {
        return
            m_tileMap->at( x, y )->isWalkable() ;
    };

    const float         vel = m_mob->getVelocity().y;
    const sf::Vector2i  pos = m_mob->getTileMapPosition();


    if ( vel > 0 )  //Check tiles below
    {
        if ( !( walkable( pos.x,
                          ( vel / Tiles::Info::SIZE ) +
                          pos.y ) ) )
        {
            invertVelocity( );
            return;
        }
    }
    else if ( vel < 0 ) //Check tiles above
    {
        if ( !( walkable( pos.x,
                          pos.y -
                          ( vel / Tiles::Info::SIZE ) ) )
           )
        {
            invertVelocity( );
            return;
        }
    }
    m_isInBadTile = false;
}

void
Tile_Collidable :: tileCollisionsXWater ()
{
    auto swimmable = [&]  ( int x, int y )
    {
        return
            m_tileMap->at( x, y )->isSwimmable() ;
    };

    const float         vel = m_mob->getVelocity().x;
    const sf::Vector2i  pos = m_mob->getTileMapPosition();

    if ( vel > 0 )  //Check tiles right
    {
        if ( !( swimmable( ( vel / Tiles::Info::SIZE ) +
                           pos.x,
                           pos.y ) ) )
        {
            invertVelocity( );
            return;
        }
    }
    else if ( vel < 0 ) //Check tiles left
    {
        if ( !( swimmable( pos.x -
                           ( vel / Tiles::Info::SIZE ),
                           pos.y ) )
           )
        {
            invertVelocity( );
            return;
        }
    }
    m_isInBadTile = false;
}

void
Tile_Collidable :: tileCollisionsYWater ()
{
    auto swimmable = [&]  ( int x, int y )
    {
        return
            m_tileMap->at( x, y )->isSwimmable() ;
    };

    const float         vel = m_mob->getVelocity().y;
    const sf::Vector2i  pos = m_mob->getTileMapPosition();


    if ( vel > 0 )  //Check tiles below
    {
        if ( !( swimmable( pos.x,
                           ( vel / Tiles::Info::SIZE ) +
                           pos.y ) ) )
        {
            invertVelocity( );
            return;
        }
    }
    else if ( vel < 0 ) //Check tiles above
    {
        if ( !( swimmable( pos.x,
                           pos.y -
                           ( vel / Tiles::Info::SIZE ) ) )
           )
        {
            invertVelocity( );
            return;
        }
    }
    m_isInBadTile = false;
}

void
Tile_Collidable :: invertVelocity  ()
{

    if ( !m_velInverted )
    {
        m_mob->setVelocity( { -m_mob->getVelocity() } );
        m_velInverted = true;   //To avoid x/y velocity inversions cancelling eachother out
    }
    m_isInBadTile = true;
}

void
Tile_Collidable :: updatePrevTile  ()
{
    if ( !m_isInBadTile )
    {
        m_prevTileMapPos = m_mob->getPosition();
    }
}



} //Namespace Component
