#ifndef TILE_INFO_H_INCLUDED
#define TILE_INFO_H_INCLUDED

#include "SFML/Graphics/Color.hpp"

struct Tile_Info
{
    bool        isWalkable;
    bool        isSwimmable;

    double      friction;
    double      viscosity;

    sf::Color   colour;
};


#endif // TILE_INFO_H_INCLUDED
