#ifndef LOOKATMOUSE_H
#define LOOKATMOUSE_H

#include "Bases/component.h"

#include <SFML/Graphics.hpp>

/*
    Makes a sprite always look at the mouse.
*/

namespace Component
{

class Look_At_Mouse : public Component_Base
{
    public:
        Look_At_Mouse( sf::RenderWindow* window, sf::Sprite* sprite );

        void
        logic ( const float dt ) override;

    private:
        sf::RenderWindow*   m_window;   //Window relative to the mouse position ( main window)
        sf::Sprite*         m_sprite;   //The sprite that gets rotated
};

} //Namespace Component

#endif // LOOKATMOUSE_H
