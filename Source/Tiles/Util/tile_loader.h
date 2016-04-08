#ifndef TILE_LOADER_H
#define TILE_LOADER_H

#include "tile_info.h"

#include <fstream>
#include <string>

class Tile_Loader
{
    public:
        void
        loadTile    ( Tile_Info* tile, const std::string filePath );

    private:
        void
        readFile    ( std::ifstream& inFile );

        const bool
        wordFound   ( std::string toFind, std::string line );

        void
        loadDouble  ( std::ifstream& inFile, double& toLoad );

        void
        loadBoolean ( std::ifstream& inFile, bool& toLoad );

        void
        loadColour  ( std::ifstream& inFile );

    private:
        //All of these are for the sake of having no spelling mistakes
        const static std::string Viscosity;
        const static std::string Friction;
        const static std::string Swimmable;
        const static std::string Walkable;
        const static std::string Colour;

        Tile_Info*      m_tile;

        unsigned        m_tileTraitsLoaded  { 0 };

        constexpr static
        unsigned        m_tileTraitsTotal   { 5 };
};


#endif // TILE_LOADER_H
