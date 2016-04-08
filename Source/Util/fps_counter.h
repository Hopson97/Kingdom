#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H

#include <SFML/Graphics.hpp>

class FPS_Counter
{
    public:
        void
        update ();

    private:
        float
        getFPS( const sf::Time& time );

    private:
        sf::Clock fpsClock;
        sf::Clock fpsClock2;
        int     fpsCount  = 0;
        float   frameTimes  = 0;

        int     frameCount      = 0;
        float   frameTimes10    = 0; //Shows average FPS every 10 secs
};

#endif // FPS_COUNTER_H
