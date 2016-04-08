#include "state_base.h"

#include "../game.h"

#include <iostream>

/**
    The base class for all the games states, such as menus, roaming, battles etc
*/

namespace State
{

State_Base :: State_Base ( Game* game)
:   mGame   ( game )
{ }

Game&
State_Base :: getGame() const
{
    return *mGame;
}

State_Base :: ~State_Base () { }

}
