#ifndef LOOKATMOUSE_H
#define LOOKATMOUSE_H

#include "Bases/component.h"

#include "../Entities/Bases/mob.h"

/*
    Makes a sprite always look at the mouse.
*/

namespace Component
{

class Look_At_Mouse : public Component_Base
{
    public:
        Look_At_Mouse( Mob* mob, sf::RenderWindow* window );

        void logic ( const float dt ) override;

    private:
        sf::RenderWindow*   m_window;   //Window relative to the mouse position ( main window)
};

} //Namespace Component

#endif // LOOKATMOUSE_H
