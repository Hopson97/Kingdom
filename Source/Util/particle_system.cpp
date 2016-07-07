#include "particle_system.h"

Particle_System :: Particle_System ( const unsigned count, const sf::Time lifetime, const sf::Color colour )
:   m_particles     ( count )
,   m_vertices      ( sf::Points, count )
,   m_lifetime      ( lifetime )
,   m_emitter       ( 0, 0 )
,   m_colour        ( colour )
{ }

void Particle_System :: setEmitter ( const sf::Vector2f& position )
{
    m_emitter = position;
}

void Particle_System :: update( const sf::Time elapsed )
{
    for (std::size_t i = 0; i < m_particles.size(); ++i)
    {
        // update the particle lifetime
        Particle& p = m_particles[i];
        p.lifetime -= elapsed;

        // if the particle is dead, respawn it
        if (p.lifetime <= sf::Time::Zero && m_update )
            resetParticle(i);

        // update the position of the corresponding vertex
        m_vertices[i].position += p.velocity * elapsed.asSeconds();

        // update the alpha (transparency) of the particle according to its lifetime
        float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
        m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
    }
}



void Particle_System :: draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
    // apply the transform
    states.transform *= getTransform();

    // our particles don't use a texture
    states.texture = NULL;

    // draw the vertex array
    target.draw(m_vertices, states);
}

void Particle_System :: resetParticle( const unsigned index )
{
    // give a random velocity and lifetime to the particle
    float angle = (std::rand() % 360) * 3.14f / 180.f;
    float speed = (std::rand() % 50) + 50.f;
    m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
    m_particles[index].lifetime = sf::milliseconds (kingdom_random::num(0, m_lifetime.asMilliseconds()));

    // reset the position of the corresponding vertex
    m_vertices[index].position = m_emitter;

    //colour
    m_vertices[index].color = m_colour;

}

void Particle_System :: setUpdate           ( const bool update )
{
    m_update = update;
}

