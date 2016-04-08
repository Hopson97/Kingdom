#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

/*
    Mainly from http://www.sfml-dev.org/tutorials/2.0/graphics-vertex-array.php
*/

#include <SFML/Graphics.hpp>
#include <vector>

#include "rand.h"
#include "maths.h"

class Particle_System : public sf::Drawable, public sf::Transformable
{
    struct Particle
    {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };

public:

    Particle_System     (  unsigned count, const sf::Time lifetime,  const sf::Color colour  );

    void
    setEmitter          ( const sf::Vector2f& position );

    void
    update              (sf::Time elapsed);

    void
    draw                (sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;

    void
    setUpdate           ( const bool update );



private:
    void resetParticle  ( const unsigned index );

    std::vector<Particle>   m_particles;
    sf::VertexArray         m_vertices;
    sf::Time                m_lifetime;
    sf::Vector2f            m_emitter;
    const sf::Color         m_colour;
    bool                    m_update        { true };
};

#endif // PARTICLE_SYSTEM_H
