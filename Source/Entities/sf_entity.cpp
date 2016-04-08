#include "sf_entity.h"



Sf_Entity :: Sf_Entity( const sf::Texture& t)
:   m_sprite ( t )
{
}

void
Sf_Entity :: draw ( sf::RenderWindow& window )
{
    if ( !inWindowBounds( window ) ) return;
    window.draw( m_sprite );
}

void
Sf_Entity :: centerSpriteOrigin ()
{
    sf::FloatRect r = m_sprite.getLocalBounds();

    m_sprite.setOrigin( r.width / 2, r.height / 2 );
}

const bool
Sf_Entity :: inWindowBounds ( const sf::RenderWindow& window) const
{
    sf::Vector2f winPos = window.getView().getCenter();

    if      ( m_sprite.getPosition().x  < winPos.x - Win_Info::WIDTH  / 2 - m_sprite.getLocalBounds().width )    return false ;
    else if ( m_sprite.getPosition().y  < winPos.y - Win_Info::HEIGHT / 2 - m_sprite.getLocalBounds().height )    return false  ;
    else if ( m_sprite.getPosition().x  > winPos.x + Win_Info::WIDTH  / 2 ) return false ;
    else if ( m_sprite.getPosition().y  > winPos.y + Win_Info::WIDTH  / 2 ) return false ;

    return true;
}
