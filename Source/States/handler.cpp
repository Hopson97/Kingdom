#include "handler.h"

/**
    State::Handler handles all the states that will be used by the main "Game" class
*/

namespace State
{


Handler :: ~Handler ()
{
    while ( !states.empty() )
    {
        popState();
    }
}

void
Handler :: changeState ( State_Base* state)
{
    popState();
    states.emplace ( std::move ( state ) );
}


void
Handler :: pushState ( State_Base* state )
{
    states.emplace ( state );
}

void
Handler :: popState ()
{
    if( !states.empty() )
    {
        delete states.top();
        states.pop();
    }
}

State_Base*
Handler :: peekState ()
{
    return states.top() ;
}

}
