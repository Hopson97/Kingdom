#ifndef HANDLER_H
#define HANDLER_H

#include <stack>

#include "state_base.h"

/**
    State::Handler handles all the states that will be used by the main "Game" class
*/

namespace State
{

class Handler
{
    public:
        ~Handler();

        void
        changeState     ( State_Base* state);

        void
        pushState       ( State_Base* state );

        void
        popState        ();

        State_Base*
        peekState       ();

        const unsigned
        size            () const  { return states.size(); }

        const bool
        empty           () const { return states.empty(); }

    private:
        std::stack<State_Base*> states;
};

}

#endif // HANDLER_H
