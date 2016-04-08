#ifndef TILE_CHUNK_H
#define TILE_CHUNK_H

#include <vector>
class Tile_Chunk
{
    public:
        Tile_Chunk();

    protected:

    private:
        std::vector<std::unique_ptr<Tiles::Tile> m_tiles;
};

#endif // TILE_CHUNK_H
