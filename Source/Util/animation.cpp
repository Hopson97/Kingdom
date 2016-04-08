#include "animation.h"

#include <iostream>

/*****************************************************************************************************************************************************************
*   addFrame()  add a frame into the std::vector of type "Frame" (struct declared in animation.h)
*   param1  :   The frame to be added into the std::vector
***************************************************************************************************************************************************************/
void
Animation::addFrame(const Frame& frame)
{
    m_frames.emplace_back(frame);
}

/*****************************************************************************************************************************************************************
*   currentFrame()  returns the current frame of which the animation is on.
*   param1  :   delta time of which to base the animation timings on
***************************************************************************************************************************************************************/
const sf::IntRect&
Animation::currentFrame( const float dt )
{
    if ( m_frames.empty() )
    {
        throw std::runtime_error ( "Animation not set up before used! ");
    }
    m_time += dt;
    std::cout << "dt: " << dt << " mtime " << m_time << std::endl;

    if ( m_time > m_frames.at( m_currFrame ).timeToNextFrame )
    {

        m_time = 0;
        m_currFrame++;
        std::cout << "next frame " << std::endl;
        if ( m_currFrame > ( m_frames.size() - 1 ) )
        {
            m_currFrame = 0;
        }
    }
    return m_frames.at( m_currFrame ).frameRectangle;
}

/*****************************************************************************************************************************************************************
*   getCurrentFrameNumber() returns whatever frame the current animation is on
***************************************************************************************************************************************************************/
const unsigned
Animation::getCurrentFrameNumber() const
{
    return m_currFrame;
}
