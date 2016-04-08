#ifndef STATE_BASE_H
#define STATE_BASE_H

/**
    The base class for all the games states, such as menus, roaming, battles etc
*/

class Game;

namespace State
{

class State_Base
{
    public:
        State_Base  ( Game* game);

        virtual
        ~State_Base ();

        virtual void
        input       ( const double dt ) = 0;

        virtual void
        update      ( const double dt ) = 0;

        virtual void
        glDraw        ( const double dt ) = 0;

        virtual void
        sfDraw        ( const double dt ) = 0;

    protected:
        Game&
        getGame() const;

    private:
        Game* mGame;
};

} //Namespace state

#endif // STATE_BASE_H
