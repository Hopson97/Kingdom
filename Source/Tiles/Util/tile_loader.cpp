#include "tile_loader.h"

#include <stdexcept>
#include <iostream>

const std::string Viscosity = "Viscosity";
const std::string Friction  = "Friction";
const std::string Swimmable = "Swimmable";
const std::string Walkable  = "Walkable";
const std::string Colour    = "Colour";


void Tile_Loader :: loadTile ( Tile_Info* tile, const std::string filePath )
{
    m_tileTraitsLoaded = 0;
    m_tile = tile;

    std::ifstream inFile    ( filePath );

    if ( !inFile.is_open() )
    {
        throw std::runtime_error ( "Tile at " + filePath + "is not a valid file name!" );
    }

    readFile( inFile );

    if ( m_tileTraitsLoaded != m_tileTraitsTotal )
    {
        throw std::runtime_error ( "Tile at " + filePath + " is an incomplete class!" );
    }

    m_tile = nullptr;
}


void Tile_Loader :: readFile ( std::ifstream& inFile )
{
    std::string   line;

    while ( std::getline( inFile, line  ) )
    {
        if ( wordFound( Viscosity, line ) ) loadDouble  ( inFile, m_tile->viscosity );
        if ( wordFound( Friction,  line ) ) loadDouble  ( inFile, m_tile->friction  );

        if ( wordFound( Walkable,  line ) ) loadBoolean ( inFile, m_tile->isWalkable  );
        if ( wordFound( Swimmable, line ) ) loadBoolean ( inFile, m_tile->isSwimmable );

        if ( wordFound( Colour,    line ) ) loadColour  ( inFile );
    }
}


bool Tile_Loader :: wordFound ( const std::string& toFind, const std::string& line ) const
{
    return line.find ( toFind ) != std::string::npos;
}

void Tile_Loader :: loadDouble ( std::ifstream& inFile, double& toLoad )
{
    inFile >> toLoad;

    m_tileTraitsLoaded++;
}

void Tile_Loader :: loadBoolean ( std::ifstream& inFile, bool& toLoad )
{
    std::string line;

    std::getline( inFile, line );

    toLoad = (line == "true") ? true : false;



    m_tileTraitsLoaded++;
}

void Tile_Loader :: loadColour  ( std::ifstream& inFile)
{
    std::cout << "Loading colour" << std::endl;
    if ( m_tileTraitsLoaded < m_tileTraitsTotal - 1 )
    {
        throw std::runtime_error ( "Colour must be defined at the end of the file!" );
    }
    int r, g, b, a;

    inFile >> r >> g >> b;

    if ( !inFile.eof() )
    {
        inFile >> a;
    }
    else
    {
        a = 255;
    }

    m_tile->colour = {
                        (sf::Uint8) r,
                        (sf::Uint8) g,
                        (sf::Uint8) b,
                        (sf::Uint8) a
                     };

    m_tileTraitsLoaded++;
}
