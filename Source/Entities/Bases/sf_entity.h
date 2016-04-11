#ifndef SF_ENTITY_H
#define SF_ENTITY_H

#include <SFML/Graphics.hpp>

#include "../../Util/window.h"


class Sf_Entity
{
    public:
        Sf_Entity           ( const sf::Texture& t );

        void
        setRotation         ( const double rot );

        float
        getRotation         () const;

        const sf::Vector2f&
        getOrigin           () const;

        void
        setPosition         ( const sf::Vector2f& pos );

        const sf::Vector2f&
        getPosition         () const;

        const sf::Vector2u
        getSpriteSize       () const;

        void
        setVelocity         ( const sf::Vector2f& velocity );

        void
        changeVelocity      ( const sf::Vector2f& velocity );

        const sf::Vector2f
        getVelocity         () const;

        void
        setColor            ( const sf::Color& col );

        virtual void
        draw                ( sf::RenderWindow& window );

    protected:
        sf::Sprite m_sprite;

        void
        centerSpriteOrigin  ();

        const bool
        inWindowBounds          ( const sf::RenderWindow& window ) const;

    private:
        sf::Vector2f m_velocity; // Left / up velocity

};

#endif // SF_ENTITY_H
