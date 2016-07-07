#include "tiles_m.h"

Tiles_M :: Tiles_M( )
{
    const static std::string tilePath   = "Res/Data/Tiles/";
    const static std::string extention  = ".tile";

    m_tileLoader.loadTile( &m_tiles[ TILE_GRASS ], tilePath + "Grass" + extention );
    m_tileLoader.loadTile( &m_tiles[ TILE_WATER ], tilePath + "Water" + extention );
    m_tileLoader.loadTile( &m_tiles[ TILE_ICE ], tilePath + "Ice" + extention );
    m_tileLoader.loadTile( &m_tiles[ TILE_CLIFF ], tilePath + "Cliff" + extention );
}

const Tile_Info& Tiles_M :: getTileInfo ( const Tile_Type tileType ) const
{
    return m_tiles.at ( tileType );
}
