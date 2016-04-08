#ifndef TILE_H
#define TILE_H

#include "sf_entity.h"
#include "game.h"
#include "ecosystems.h"

/*
    Represents a single tile in the world.
*/

namespace Tiles
{

namespace Info
{
    constexpr static
    int     SIZE        { 42 },     //The size of a single tile in pixels ( squared )
            MAP_SIZE    { 1500 };    //How size of the map in tiles ( squared )

    const unsigned TEXTURE_VARIANTS = 3;

    namespace Colours
    {
        const static sf::Color grass   = { 0,   255, 50,   };
        const static sf::Color sea     = { 58,  80,  230,  };
        const static sf::Color cliff   = { 255, 255, 255,  };
        const static sf::Color ice     = { 50 , 229, 255   };
    }
}


class Tile : public Sf_Entity
{
    friend class Tile_Loader;

    public:
        Tile (  const Game& game, const sf::Vector2i& pos, const sf::Color colour,
                const Ecosystem ecosytem, const bool walkable,
                const bool swimmable, const double friction = 1 );
        void
        draw                ( sf::RenderWindow& window) override;

        inline
        const bool
        isWalkable          ()          { return m_isWalkable; }

        inline
        const bool
        isSwimmable          ()          { return m_isSwimmable; }

        inline
        const sf::Vector2i
        getTileMapPos       () const    { return m_tilePos; }

        inline
        const double
        getFriction         ( ) const   { return m_friction; }

        inline
        const Ecosystem
        getEcosystem        () const    { return m_ecosystem; }

        //Virtual members
        virtual void
        update              ( const float dt ) { }

        virtual void
        steppedOn           ( ) { }

    protected:
        const sf::Texture&
        randomTexture       (  const Game& game  );

        const sf::Texture&
        getTexture          ( const Game& game, const unsigned id );

        inline
        const unsigned
        getTxrId            () const     { return m_txrId; }

    private:
        bool                m_isWalkable;
        bool                m_isSwimmable;

        sf::Vector2i        m_tilePos;

        unsigned            m_txrId;
        const double        m_friction;

        Ecosystem           m_ecosystem;
};

} //namespace Tiles

#endif // TILE_H
