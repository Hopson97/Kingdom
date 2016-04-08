#include "game.h"

#include "States/test.h"

Game :: Game ()
{
    m_states.changeState( new State::Test ( this ) );
}


void
Game :: runLoop ()
{
    sf::Clock dtClock;
    const   sf::Time timeStep = sf::microseconds(50);
            sf::Time accumulated_dt;
    dtClock.restart();

    while ( m_window.isOpen() )
    {
        if ( !m_states.empty() )
        {
            double dt = calculateDeltaTime( dtClock, accumulated_dt );

            m_window.clear( );

            m_states.peekState()->input         ( dt );
            if ( accumulated_dt >= timeStep )
            {
                accumulated_dt -= timeStep;
                m_states.peekState()->update    ( timeStep.asSeconds() );
            }
            m_states.peekState()->glDraw        ( dt );
            m_states.peekState()->sfDraw        ( dt );

            m_window.update();
        }
        else
        {
            m_window.close();
            break;
        }
        fps.update();
    }
}

const double
Game :: calculateDeltaTime ( sf::Clock& c, sf::Time& t )
{
    sf::Time dt = c.restart();
    t += dt;
    return dt.asSeconds();
}

const sf::Texture&
Game :: getTexture ( const Texture_Name name )  const
{
    return m_textures.getTexture( name );
}

