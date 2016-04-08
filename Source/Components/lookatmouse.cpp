#include "lookatmouse.h"

#include "maths.h"

namespace Component
{

Look_At_Mouse :: Look_At_Mouse ( sf::RenderWindow* window, sf::Sprite* sprite )
:   m_window        ( window )
,   m_sprite        ( sprite )
{
}

void
Look_At_Mouse :: logic ( const float dt )
{
    float dx;
    float dy;

    sf::Vector2f pos = m_sprite->getPosition();    //Get sprite position
    sf::Vector2f mousePos = m_window->mapPixelToCoords ( sf::Mouse::getPosition( *m_window ) );  //Get mouse

    dx = pos.x - mousePos.x;    //Returns distance between mouseX and playerX
    dy = pos.y - mousePos.y;


    float rot = (atan2(dy,dx)) * 180 / Math::PI + 180;

    m_sprite->setRotation( rot );
}

} //Namespace Component
