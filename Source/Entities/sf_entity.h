#ifndef SF_ENTITY_H
#define SF_ENTITY_H

#include <SFML/Graphics.hpp>

#include "Util/window.h"


class Sf_Entity
{
    public:
        Sf_Entity           ( const sf::Texture& t );

        void
        setRotation         ( const double rot )                { m_sprite.setRotation( rot ); }

        float
        getRotation         () const                            { return m_sprite.getRotation(); }

        const sf::Vector2f&
        getOrigin           () const                            { return m_sprite.getOrigin(); }

        void
        setPosition         ( const sf::Vector2f& pos )         { m_sprite.setPosition( pos ); }

        const sf::Vector2f&
        getPosition         ()                                  { return m_sprite.getPosition(); }

        const sf::Vector2u
        getSpriteSize       ()                                  { return m_sprite.getTexture()->getSize(); }

        void
        setVelocity         ( const sf::Vector2f& velocity )    { m_velocity = velocity; }

        void
        changeVelocity      ( const sf::Vector2f& velocity )    { m_velocity += velocity; }

        const sf::Vector2f
        getVelocity         () const                            { return m_velocity; }


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
