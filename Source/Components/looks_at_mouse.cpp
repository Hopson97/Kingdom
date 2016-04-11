#include "looks_at_mouse.h"

#include "maths.h"

namespace Component
{

Look_At_Mouse :: Look_At_Mouse ( Mob* mob, sf::RenderWindow* window )
:  Component_Base   ( mob )
,   m_window        ( window )
{
}

void
Look_At_Mouse :: logic ( const float dt )
{
    sf::Vector2f pos = m_mob->getPosition();    //Get sprite position
    sf::Vector2f mousePos = m_window->mapPixelToCoords ( sf::Mouse::getPosition( *m_window ) );  //Get mouse

    float dx = pos.x - mousePos.x;    //Returns distance between mouseX and playerX
    float dy = pos.y - mousePos.y;

    m_mob->setRotation( Math::getRot( dx, dy ) ); //"getRot" Defined in Util/maths.h
}

} //Namespace Component
