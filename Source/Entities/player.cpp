#include "player.h"

#include "../Util/maths.h"

#include "looks_at_mouse.h"
#include "tile_collidable.h"
#include "steps_on_tiles.h"
#include "ground_friction.h"
#include "swimmable.h"



Player :: Player ( Game* game, Tile_Map* tiles )
:   Mob         ( game, game->getTexture ( TXR_ENT_PLAYER), tiles  )
,   m_window    ( &game->getWindow().get() )
{
    centerSpriteOrigin  ( );
    m_view.setSize      ( Win_Info::WIDTH, Win_Info::HEIGHT );

    addComponent( std::make_unique<Component::Look_At_Mouse>
                  ( this, &game->getWindow().get() ) );

    addComponent( std::make_unique<Component::Steps_On_Tiles>
                  ( this, m_tileMap ) );

    addComponent( std::make_unique<Component::Ground_Friction>
                  ( this, m_tileMap ) );

    addComponent( std::make_unique<Component::Swimmable>
                  ( this, m_tileMap, true, *game ) );

    addComponent( std::make_unique<Component::Tile_Collidable>
                  ( this, m_tileMap ) );

    //setUpAnimation();

    setPosAtSolidTile   ( );
}

void
Player :: input   ( const float dt )
{
    m_isMoving = false;

    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )
    {
        velocityForwards    ( dt );
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) )
    {
        velocityBackwards   ( dt );
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
    {
        velocityLeft        ( dt );
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
    {
        velocityRight       ( dt );

    }

    if ( m_isMoving )
    {
        //m_sprite.setTextureRect ( m_walkAnim.currentFrame( dt ) );
    }
}

void
Player :: uniqueLogic  ( const float dt )
{
    updateView();
}

void
Player :: updateView ()
{
    m_view.setCenter( m_sprite.getPosition() );   //Centres camera
    //to the player
    m_window->setView(m_view);      //Set the windows view to the camera
}
/*
void
Player :: setUpAnimation ()
{
    const int WIDTH     = 20;
    const int HEIGHT    = 25;
    const float time = 0.01;

    sf::IntRect standing    ( 0,            0, WIDTH, HEIGHT );
    sf::IntRect walk1       ( WIDTH,        0, WIDTH, HEIGHT );
    sf::IntRect walk2       ( WIDTH * 2,    0, WIDTH, HEIGHT );

    m_walkAnim.addFrame( { standing,  time } );
    m_walkAnim.addFrame( { walk1,     time } );
    m_walkAnim.addFrame( { standing,  time } );
    m_walkAnim.addFrame( { walk2,     time } );
}
*/
