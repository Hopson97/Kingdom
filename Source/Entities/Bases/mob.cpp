#include "mob.h"

#include "maths.h"

Mob :: Mob ( Game* game, const sf::Texture& texture, Tile_Map* tiles )
:   Sf_Entity   ( texture )
,   m_game      ( game )
,   m_tileMap   ( tiles )
{
    updateTileMapPos    ( );

    m_mobState = Mob_State::MOB_STATE_GROUND;
}

void
Mob :: update ( const float dt  )
{
    //Check for the mob being OOB of the map
    {
        int mapSize = Tiles::Info::MAP_SIZE * Tiles::Info::SIZE;

        int spriteWidth = m_sprite.getLocalBounds().width;
        int spriteHeight = m_sprite.getLocalBounds().height;
        sf::Vector2f spritePos = m_sprite.getPosition();


        if ( spritePos.x >= mapSize - spriteWidth - 1 )
        {
            m_sprite.setPosition( mapSize - spriteWidth - 1, spritePos.y  );
        }
        if ( spritePos.x + 1 <= 1 )
        {
            m_sprite.setPosition( spriteWidth, spritePos.y );
        }


        if ( spritePos.y > mapSize - spriteHeight - 1 )
        {
            m_sprite.setPosition( spritePos.x, mapSize - spriteHeight - 1 );
        }
        if ( spritePos.y + 1 <= 1 )
        {
            m_sprite.setPosition( spritePos.x, 1 );
        }
    }
    checkVel();
    updateTileMapPos();
    uniqueLogic     ( dt );
    componentLogic  ( dt );

    m_sprite.move( getVelocity().x, getVelocity().y );
}

const sf::Vector2i&
Mob :: getTileMapPosition  ()
{
    updateTileMapPos();
    return m_tileMapPos;
}

void
Mob :: addComponent    (  Comp c  )
{
    m_components.push_back( std::move ( c )  );
}

void
Mob :: componentLogic ( const float dt )
{
    for ( auto& component : m_components )
    {
        component->logic( dt );
    }
}

void
Mob :: velocityForwards    ( const float dt )
{
    const double rot = Math::toRads ( m_sprite.getRotation() );

    changeVelocity( { 0, ( m_walkSpeed * (float)sin ( rot ) ) * dt    } );
    changeVelocity( {    ( m_walkSpeed * (float)cos ( rot ) ) * dt, 0 } );

    m_isMoving = true;
}

void
Mob :: velocityBackwards   ( const float dt )
{
    const double rot = Math::toRads ( m_sprite.getRotation() );

    changeVelocity( { 0, -( m_walkSpeed * (float)sin ( rot ) ) * dt    } );
    changeVelocity( {    -( m_walkSpeed * (float)cos ( rot ) ) * dt, 0 } );

    m_isMoving = true;
}

void
Mob :: velocityLeft        ( const float dt )
{
    const double rot = Math::toRads ( m_sprite.getRotation() + 90 );

    changeVelocity( { 0, -( m_walkSpeed * (float)sin ( rot ) ) * dt    } );
    changeVelocity( {    -( m_walkSpeed * (float)cos ( rot ) ) * dt, 0 } );

    m_isMoving = true;
}

void
Mob :: velocityRight       ( const float dt )
{
    const double rot = Math::toRads ( m_sprite.getRotation() + 90 );

    changeVelocity( { 0, ( m_walkSpeed * (float)sin ( rot ) ) * dt    } );
    changeVelocity( {    ( m_walkSpeed * (float)cos ( rot ) ) * dt, 0 } );

    m_isMoving = true;
}

void
Mob :: updateTileMapPos ()
{
    sf::Vector2i pos;
    pos.x = m_sprite.getPosition().x;
    pos.y = m_sprite.getPosition().y;

    int x = (pos.x / Tiles::Info::SIZE);
    int y = (pos.y / Tiles::Info::SIZE);

    m_tileMapPos = sf::Vector2i ( x, y );
}

//Makes sure the mob can go to a complete stop and applies friction
void
Mob :: checkVel ( )
{
    const float bound = 0.01;

    if ( getVelocity().x < bound &&  getVelocity().x > -bound ) setVelocity( { 0, getVelocity().y } );
    if ( getVelocity().y < bound &&  getVelocity().y > -bound ) setVelocity( { getVelocity().x, 0 } );
}

void
Mob :: setPosAtSolidTile ()
{
    for ( int y = 0 ; y < Tiles::Info::MAP_SIZE ; y ++ )
    {
        for ( int x = 0 ; x < Tiles::Info::MAP_SIZE; x++ )
        {
            if ( m_tileMap->at(x, y)->isWalkable() )
            {
                m_sprite.setPosition ( x * Tiles::Info::SIZE, y * Tiles::Info::SIZE );
            }
        }
    }
}

void
Mob :: setTarget   ( Mob* mob )
{
    m_target = mob;
}


const Mob*
Mob :: getTarget    () const
{
    return ( m_target ) ? m_target : nullptr;
}

const sf::Vector2i
Mob :: getTargetTilePosition    ()
{
    return ( m_target ) ? m_target->getTileMapPosition() : sf::Vector2i( 0, 0 );
}

const bool
Mob :: hasTarget () const
{
    return ( m_target ) ? true : false;
}

