#include "textures.h"

Textures :: Textures()
{
    loadTileTextures    ();
    loadEntityTextures  ();
    loadTreeTextures    ();
}

void
Textures :: loadTileTextures()
{
    const std::string tilePath = "Res/Tiles/";

    loadTexture ( TXR_TILE,  tilePath + "Tile.png" );
    loadTexture ( TXR_TILE2, tilePath + "Tile2.png" );
    loadTexture ( TXR_TILE3, tilePath + "Tile3.png" );
}

void
Textures :: loadEntityTextures  ()
{
    const std::string entityPath = "Res/Entities/";

    loadTexture( TXR_ENT_PLAYER, entityPath + "Player.png" );
    loadTexture( TXR_ENT_ZOMBIE, entityPath + "Zombie.png" );
    loadTexture( TXR_ENT_WHALE,  entityPath + "Whale.png" );
}

void
Textures :: loadTreeTextures  ()
{
    const std::string effectPath = "Res/Trees/";

    //loadTexture( TXR_TREE_REG, effectPath + "Tree1.png");
}

const sf::Texture&
Textures :: getTexture( const Texture_Name name ) const
{
    return m_textureMap.at( name );
}


void
Textures :: loadTexture ( const Texture_Name name, const std::string& path )
{
    if ( !m_textureMap[ name ].loadFromFile( path ) )
    {
        throw std::runtime_error ( "Texture file at " + path + " does not exist.");
    }

    m_textureMap[ name ].setSmooth( true );
}
