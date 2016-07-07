#include "sf_entity.h"



Sf_Entity :: Sf_Entity( const sf::Texture& t)
    :   m_sprite ( t )
{
}


void Sf_Entity :: draw ( sf::RenderWindow& window )
{
    if ( !inWindowBounds( window ) ) return;
    window.draw( m_sprite );
}


void Sf_Entity :: centerSpriteOrigin ()
{
    sf::FloatRect r = m_sprite.getLocalBounds();

    m_sprite.setOrigin( r.width / 2, r.height / 2 );
}


bool Sf_Entity :: inWindowBounds ( const sf::RenderWindow& window) const
{
    sf::Vector2f winPos = window.getView().getCenter();

    if      ( m_sprite.getPosition().x  < winPos.x - Win_Info::WIDTH  / 2 - m_sprite.getLocalBounds().width )    return false ;
    else if ( m_sprite.getPosition().y  < winPos.y - Win_Info::HEIGHT / 2 - m_sprite.getLocalBounds().height )    return false  ;
    else if ( m_sprite.getPosition().x  > winPos.x + Win_Info::WIDTH  / 2 ) return false ;
    else if ( m_sprite.getPosition().y  > winPos.y + Win_Info::WIDTH  / 2 ) return false ;

    return true;
}


void Sf_Entity :: setRotation ( const double rot )
{
    m_sprite.setRotation( rot );
}


float Sf_Entity :: getRotation () const
{
    return m_sprite.getRotation();
}


const sf::Vector2f& Sf_Entity :: getOrigin () const
{
    return m_sprite.getOrigin();
}


void Sf_Entity :: setPosition ( const sf::Vector2f& pos )
{
    m_sprite.setPosition( pos );
}


const sf::Vector2f& Sf_Entity :: getPosition () const
{
    return m_sprite.getPosition();
}


const sf::Vector2u Sf_Entity :: getSpriteSize () const
{
    return m_sprite.getTexture()->getSize();
}


void Sf_Entity :: setVelocity ( const sf::Vector2f& velocity )
{
    m_velocity = velocity;
}


void Sf_Entity :: changeVelocity ( const sf::Vector2f& velocity )
{
    m_velocity += velocity;
}


const sf::Vector2f Sf_Entity :: getVelocity () const
{
    return m_velocity;
}


void Sf_Entity :: setColor ( const sf::Color& col )
{
    m_sprite.setColor( col );
}
