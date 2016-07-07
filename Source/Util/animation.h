#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>

struct Frame
{
    sf::IntRect     frameRectangle;
    float           timeToNextFrame;
};

class Animation
{
    public:
        void addFrame	(const Frame& frame);

        const sf::IntRect& currentFrame	(const float dt); //, sf::Sprite& sprite);

        unsigned getCurrentFrameNumber	() const;

    private:
        std::vector<Frame> m_frames;

        float           m_time       { 0 };
        unsigned        m_currFrame  { 0 };





};

#endif // ANIMATION_H
