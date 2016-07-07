#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

namespace Win_Info
{
    constexpr int HEIGHT = 690;
    constexpr int WIDTH  = 1280;
}

class Window
{
    public:
        Window	();

        sf::RenderWindow& get	();

        void clear	();

        void update	();

        bool isOpen	();

        void close	();

        void pushGLStates	();

        void popGLStates	();

    private:
        void winEvents		();


    private:
        sf::RenderWindow m_window;
};

#endif // WINDOW_H
