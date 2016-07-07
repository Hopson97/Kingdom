#ifndef TILES_M_H
#define TILES_M_H

#include <map>

#include "../Tiles/Util/tile_loader.h"
#include "../Tiles/Util/tile_info.h"

enum Tile_Type
{
        TILE_GRASS
    ,   TILE_WATER
    ,   TILE_ICE
    ,   TILE_CLIFF
};

class Tiles_M
{
    public:
        Tiles_M();

        const Tile_Info& getTileInfo ( const Tile_Type tileType ) const;

    private:
        Tile_Loader    m_tileLoader;

        std::map<Tile_Type, Tile_Info>    m_tiles;
};

#endif // TILES_M_H
