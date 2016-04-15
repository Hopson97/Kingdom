#ifndef TILE_H
#define TILE_H


#include "../../Entities/Bases/sf_entity.h"

#include "../../Light/light.h"

#include "../../game.h"

#include "../Util/ecosystems.h"
#include "../Util/tile_info.h"




/*
    Represents a single tile in the world.
*/

namespace Tiles
{

namespace Info
{
    constexpr static
    int     SIZE        { 42 },     //The size of a single tile in pixels ( squared )
            MAP_SIZE    { 1300 };    //How size of the map in tiles ( squared )

    const unsigned TEXTURE_VARIANTS = 3;
}


class Tile : public Sf_Entity
{
    public:
        Tile (  const Game& game, const sf::Vector2i& pos,
                const Ecosystem ecosystem, const sf::Color& light );

        void
        draw                    ( sf::RenderWindow& window) override;

        const bool
        isWalkable              () const;

        const bool
        isSwimmable             () const;

        const sf::Vector2i&
        getTileMapPos           () const;

        const double
        getFriction             () const;

        const double
        getViscosity            () const;

        const Ecosystem
        getEcosystem            () const;

        const sf::Color&
        getLight                () const;

        virtual void
        update                  ( const float dt );

        virtual void
        steppedOn               ()
        { }

        void
        updateLight             ( const std::vector<Light>& lights );

    protected:
        const sf::Texture&
        randomTexture           (  const Game& game  );

        const sf::Texture&
        getTexture              ( const Game& game, const unsigned id );

        const unsigned
        getTxrId                () const;

        void
        setInfo                 ( const Tile_Info& info );

        void
        applyLight              ();

    private:
        Tile_Info           m_info;

        sf::Vector2i        m_tilePos;
        Ecosystem           m_ecosystem;
        unsigned            m_txrId;

        sf::Color           m_light         { 0, 0, 0 };

        bool                m_hasUpdated    { false };
};

} //namespace Tiles

#endif // TILE_H
