#ifndef GAME_H
#define GAME_H

#include "Util/window.h"

#include "States/handler.h"
#include "Managers/textures.h"
#include "fps_counter.h"

class Game
{
    public:
        Game                        ();

        void
        runLoop                     ();

        const  sf::Texture&
        getTexture                  ( const Texture_Name name ) const;

        State::Handler&
        states                      ()                          { return m_states; }

        Window&
        getWindow                   ()                          { return m_window; }



    private:
        Window m_window;
        State::Handler m_states;

        const   double              calculateDeltaTime          ( sf::Clock& c, sf::Time& t );

        Textures m_textures;

        FPS_Counter fps;
};

#endif // GAME_H
