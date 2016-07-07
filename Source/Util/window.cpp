#include "window.h"

#include <GL/glew.h>

Window :: Window()
{
    //General window stuff
    m_window.create ( sf::VideoMode(Win_Info::WIDTH, Win_Info::HEIGHT),
                      "Window",
                      sf::Style::Default,
                      sf::ContextSettings(24) );
    m_window.setFramerateLimit ( 120 );
    m_window.setPosition( { 0, 0 } );

}

sf::RenderWindow& Window :: get()
{
    return m_window;
}

void Window :: clear ( )
{
    m_window.clear();
}

void Window :: update ()
{
    m_window.display();
    winEvents();
}

bool Window :: isOpen ()
{
    return m_window.isOpen();
}

void Window :: winEvents ()
{
    sf::Event e;

    while ( m_window.pollEvent ( e ) )
    {
        if ( e.type == sf::Event::Closed )
        {
            m_window.close();
        }
        else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
        {
            m_window.close();
        }
    }
}

void Window :: close ()
{
    m_window.close();
}

void Window :: pushGLStates ()
{
    //m_window.pushGLStates();
    //m_window.resetGLStates();
}

void Window :: popGLStates ()
{
    //m_window.popGLStates();
}
