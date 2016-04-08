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
        void
        addFrame                (const Frame& frame);

        const sf::IntRect&
        currentFrame            (const float dt); //, sf::Sprite& sprite);

        const unsigned
        getCurrentFrameNumber   () const;

    private:
        std::vector<Frame> mFrames;

        float           mTime       { 0 };
        unsigned        mCurrFrame  { 0 };





};

#endif // ANIMATION_H
