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
