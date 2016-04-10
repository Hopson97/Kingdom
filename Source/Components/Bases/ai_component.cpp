#include "ai_component.h"

namespace Component
{

    //This class seems pointless right now, but is going to be expanded in the future


const unsigned
AI_Component :: getDistanceTo ( const sf::Vector2i& otherPos ) const
{
    int dy = abs ( otherPos.y - m_mob->getTileMapPosition().y );
    int dx = abs ( otherPos.x - m_mob->getTileMapPosition().x );

    return  sqrt( pow ( dx, 2 ) + pow ( dy, 2 ) );
}

}
