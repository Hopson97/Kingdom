#include "fps_counter.h"

#include <iostream>

void
FPS_Counter :: update ()
{
    float fpsThisFrame = getFPS( fpsClock.restart() );
    frameTimes      += fpsThisFrame;

    fpsCount ++;

    if ( fpsClock2.getElapsedTime().asSeconds() >= 1 ) {
        std::cout << frameTimes / fpsCount << std::endl;
        frameTimes  = 0;
        fpsCount    = 0;
        fpsClock2.restart();
        frameCount ++;
    }
}

float
FPS_Counter :: getFPS(const sf::Time& time)
{
    return (1000000.0f / time.asMicroseconds());
}
