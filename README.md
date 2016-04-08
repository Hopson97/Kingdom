# Kingdom

Created using C++ and SFML, this is a game where the world is viewed from a top down perspective.

The earliest screenshot of the game is this, showing grass tiles and random water tiles. It was created during the testing of tile collisons.

The tile collisions were somewhat awkward to do as unlike other tile games, the player is not restricted to be in the square, meaning they can go in any direction they like and move anywhere in a square.

![alt text](http://puu.sh/o5LGX/145d3f5ef8.png "Water and grass")

#Entities 

All entities (exluding tiles, meaning only the entities in the Entities folder) are based of a component based class system. This means that entities must inherit from "Mob". The "Mob" class has a list of components, which get cycled through every frame in the update method of the mob, after doing any unique logic of a derived mob class first.

Components are in the "Component" folder, and inherit from the "Component::Component_Base" class, and implement the logic method from the base.

It is then very easy to add logic to the Entities as you can simply do it in a header include and a couple lines of code in the Entities constructor. For example, to make an derived mob collide with tiles:


```C++

addComponent( std::make_unique<Component::Tile_Collidable>
            ( m_tileMap, this ) );

```

std::unique_ptr is used for all polymorphism for memory safety.

#Tiles

Tiles are bit odd, as I decided to only have 3 varients of tile textures and then colour them in the code. That texture looks like this: 

![alt text](http://puu.sh/o5LKn/7db0b89aa2.png "Tile texture")

The jigsaw style edges allows for the tiles to easily interlock with eachother and sort of "blend" with tiles of not the same type without looking too square.

All tiles must inherit from the base "Tiles::Tile" class, and pass along some basic information such as location and colour.

Each tile type also has a respective .tile (custom file type) in Res/Data/Tiles/ which allows much easier changes for tile types, eg their friction or viscosity values. The format is as follows, as shown by the Grass.tile file as an example:

...........

Viscosity

0

Friction

0.76

Swimmable

false

Walkable

true

Colour

0 255 50

..................

The information can go in any order, except the RGBA colour values must go at the bottom due to a possible alpha value at the end, and the current way of detection for that is checking for the EOF.

Thanks to the "Component::Steps_On_Tiles" class and the "steppedOn()" method of tiles, it is also possible to trigger events when walking on tiles. For example, here a screenshot of water turning into ice when stepped on, simply by adding that logic to the Tiles::Water_Tile class, and then adding the "Steps_On_Tiles" component to the Player class.

![alt text](http://puu.sh/oaC00/1ebc3d575f.png "Frozone!")

#Level generation

Much room for improvement.

As of now, the whole map is filled with water and then randomly place islands are "genertated". Here is a couple of zoomed out views of that:


![alt text](http://puu.sh/o9If7/d010bdb301.png "Level Gen 1")
![alt text](http://puu.sh/oaCau/085eed1b90.png "Level Gen 2")

# Rendering

Only tiles within the view are updated and drawn, allowing for 1 million tiles and still run at 120 FPS. The tile map has a vector of tiles, and then selects which ones to draw

```C++

void
Tile_Map :: draw ( sf::RenderWindow& window, const sf::Vector2i& playerTilePos )
{
    const int tilesX = (Win_Info::WIDTH / Tiles::Info::SIZE) + 3; //Width of the screen in tiles
    const int tilesY = (Win_Info::WIDTH / Tiles::Info::SIZE) + 3;

    int xStart = playerTilePos.x - tilesX; //Start of the render bounds
    int xEnd = playerTilePos.x + tilesX;  //End of the render bounds

    if ( xStart < 0 ) xStart = 0; //Make sure the tile range is actually within the maps bounds
    if ( xEnd > Tiles::Info::MAP_SIZE - 1 ) xEnd = Tiles::Info::MAP_SIZE - 1;

    int yStart = playerTilePos.y - tilesY;
    int yEnd = playerTilePos.y + tilesY;

    if ( yStart < 0 ) yStart = 0;
    if ( yEnd > Tiles::Info::MAP_SIZE - 1 ) yEnd = Tiles::Info::MAP_SIZE - 1;

    //Only drawing those tiles
    for ( int y = yStart ; y < yEnd ; y++ )
    {
        for ( int x = xStart ; x < xEnd ; x++ )
        {
            this->at( x, y )->draw ( window );
        }
    }
}

```



