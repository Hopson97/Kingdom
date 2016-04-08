#include "textures.h"

#include <iostream>

Textures :: Textures()
{
    loadTileTextures();
    loadEntityTextures();
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

const sf::Texture&
Textures :: getTexture( const Texture_Name name ) const
{                            //Causes crash
    if ( m_textureMap.empty() ) throw std::runtime_error ( "Texture map empty" );       //m_textureMap.empty() causes crash
    return m_textureMap.at( name );                                                     //Causes crash
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
