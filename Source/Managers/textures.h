#ifndef TEXTURES_H
#define TEXTURES_H

#include <map>
#include <SFML/Graphics.hpp>

enum Texture_Name
{
        TXR_TILE
    ,   TXR_TILE2
    ,   TXR_TILE3

    ,   TXR_ENT_PLAYER
    ,   TXR_ENT_ZOMBIE
    ,   TXR_ENT_WHALE

    ,   TXR_TREE_REG
};

class Textures
{
    public:
        Textures();

        const sf::Texture& getTexture          ( const Texture_Name name ) const;

    private:
        void loadTileTextures    ();

        void loadEntityTextures  ();

        void loadTreeTextures    ();

        void loadTexture         ( const Texture_Name name, const std::string& path );




    private:
        std::map<Texture_Name, sf::Texture> m_textureMap;
};

#endif // TEXTURES_H
