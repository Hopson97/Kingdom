#ifndef SF_ENTITY_H
#define SF_ENTITY_H

#include <SFML/Graphics.hpp>

#include "Util/window.h"


class Sf_Entity
{
    public:
        Sf_Entity                   ( const sf::Texture& t );

        inline
        void
        setRotation ( const double rot )        { m_sprite.setRotation( rot ); }

        inline
        void
        setPosition ( const sf::Vector2f& pos ) { m_sprite.setPosition( pos ); }

        inline
        const sf::Vector2f&
        getPosition (   )                       { return m_sprite.getPosition(); }

        virtual void
        draw                        ( sf::RenderWindow& window );

    public: //Fundamental getters and setters
        inline
        void
        setVelocity             ( const sf::Vector2f& velocity )        { m_velocity = velocity; }

        inline
        void
        changeVelocity          ( const sf::Vector2f& velocity )        { m_velocity += velocity; }

        inline
        const sf::Vector2f
        getVelocity             ( ) const                               { return m_velocity; }

    protected:
        sf::Sprite m_sprite;

        void
        centerSpriteOrigin      ();

        const bool
        inWindowBounds          ( const sf::RenderWindow& window ) const;

    private:
        sf::Vector2f m_velocity; // Left / up velocity

};

#endif // SF_ENTITY_H
