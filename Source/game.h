#ifndef GAME_H
#define GAME_H

#include "Util/window.h"

#include "States/handler.h"
#include "Managers/textures.h"
#include "Managers/tiles_m.h"

#include "Util/fps_counter.h"

class Game
{
    public:
        Game                        ();

        void
        runLoop                     ();

        const  sf::Texture&
        getTexture                  ( const Texture_Name name ) const;

        const  Tile_Info&
        getTileInfo                 ( const Tile_Type name ) const;

        State::Handler&
        states                      ();

        Window&
        getWindow                   ();



    private:
        Window m_window;
        State::Handler m_states;

        const double
        calculateDeltaTime          ( sf::Clock& c, sf::Time& t );

        Textures    m_textures;
        Tiles_M     m_tileInfo;

        FPS_Counter fps;
};

#endif // GAME_H
