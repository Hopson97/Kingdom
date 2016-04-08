#ifndef TILE_H
#define TILE_H

#include "sf_entity.h"
#include "game.h"
#include "ecosystems.h"
#include "tile_info.h"

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
        const static sf::Color grass   = { 0,   255, 50    };
        const static sf::Color sea     = { 58,  80,  230, 200    };
        const static sf::Color cliff   = { 255, 255, 255   };
        const static sf::Color ice     = { 50 , 229, 255   };
    }
}


class Tile : public Sf_Entity
{
    public:
        Tile (  const Game& game, const sf::Vector2i& pos, const Ecosystem ecosystem );

        void
        draw                ( sf::RenderWindow& window) override;

        inline
        const bool
        isWalkable          ()              { return m_info.isWalkable; }

        const bool
        isSwimmable          ()             { return m_info.isSwimmable; }

        const sf::Vector2i
        getTileMapPos       () const        { return m_tilePos; }

        const double
        getFriction         () const        { return m_info.friction; }

        const double
        getViscosity       () const         { return m_info.viscosity; }

        const Ecosystem
        getEcosystem        () const        { return m_ecosystem; }

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

        const unsigned
        getTxrId            () const     { return m_txrId; }

        void
        setInfo             ( const Tile_Info& info );

    private:
        Tile_Info     m_info;

        sf::Vector2i        m_tilePos;
        Ecosystem           m_ecosystem;
        unsigned            m_txrId;


};

} //namespace Tiles

#endif // TILE_H
