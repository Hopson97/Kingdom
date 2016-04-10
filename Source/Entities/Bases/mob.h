#ifndef MOB_H
#define MOB_H

#include "Bases/component.h"
#include "sf_entity.h"
#include "tilemap.h"

#include <vector>
#include <memory>

#include "game.h"

enum Mob_State
{
        MOB_STATE_AIR
    ,   MOB_STATE_GROUND
    ,   MOB_STATE_WATER
};

class Mob : public Sf_Entity
{
    using Comp = std::unique_ptr<Component::Component_Base>;



    public:
        const sf::Vector2i&
        getTileMapPosition  ();

        void
        update              ( const float dt );

        const bool
        isAlive             ( )                         { return m_isLiving; }

        void
        setAlive            ( const bool alive )        { m_isLiving = alive; }

        void
        setMobState         ( const Mob_State state )   { m_mobState = state; }

        const Mob_State
        getMobState         ( )                          { return m_mobState; }

        void
        velocityForwards    ( const float dt );

        void
        velocityBackwards   ( const float dt );

        void
        velocityLeft        ( const float dt );

        void
        velocityRight       ( const float dt );

        void
        setTarget                   ( Mob* mob );

        const Mob*
        getTarget                   () const;

        const sf::Vector2i
        getTargetTilePosition       ();

        const bool
        hasTarget                   () const;


    protected:
        Mob ( Game* game, const sf::Texture& texture, Tile_Map* tiles );

        virtual void
        uniqueLogic         ( const float dt ) = 0;

        void
        addComponent        ( Comp c );

        void
        updateTileMapPos    ();


    protected:
        Game*           m_game;
        Tile_Map*       m_tileMap;
        bool            m_isMoving  { false };

        Mob*            m_target            { nullptr };

        void
        setPosAtSolidTile   ();

    private:
        void
        componentLogic      ( const float dt );

        void
        checkVel            ( );

    private:
        std::vector< Comp > m_components;

        sf::Vector2i    m_tileMapPos;

        bool            m_isLiving;

        Mob_State       m_mobState;

    protected: //temp
        /*const*/ float     m_walkSpeed { 25 };
};

#endif // MOB_H
