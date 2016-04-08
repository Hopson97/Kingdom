#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

namespace Win_Info
{
    constexpr int HEIGHT = 690;
    constexpr int WIDTH  = 1280;
}

struct RGBA
{
    float   r,
            g,
            b,
            a;
    void check ()
    {
        checkF( r );
        checkF( g );
        checkF( b );
        checkF( a );
    }

    private:
        void checkF ( float& f )
        {
            if ( f < 0.0f || f > 1.0f )
            {
                f = 0.0f;
            }
        }

};

class Window
{
    public:
        Window();

        sf::RenderWindow&
        get                 ();

        void
        clear               ( RGBA colour = { 0.0f, 0.0f, 0.0f, 1.0f } );

        void
        update              ();

        const bool
        isOpen              ();

        void
        close               ();

        void
        pushGLStates        ();

        void
        popGLStates         ();

    private:
        void
        winEvents           ();


    private:
        sf::RenderWindow m_window;
};

#endif // WINDOW_H
