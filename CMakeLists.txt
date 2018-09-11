cmake_minimum_required(VERSION 3.1)

project(kingdom)
set (CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED graphics window system)

#Add files
set(SOURCES 
    Source/game.cpp
    Source/main.cpp
    Source/Util/animation.cpp
    Source/Util/particle_system.cpp
    Source/Util/fps_counter.cpp
    Source/Util/rand.cpp
    Source/Util/window.cpp
    Source/Managers/textures.cpp
    Source/Managers/tiles_m.cpp
    Source/Components/effected_by_light.cpp
    Source/Components/swimmable.cpp
    Source/Components/spawns_ground.cpp
    Source/Components/looks_at_mouse.cpp
    Source/Components/tile_collidable.cpp
    Source/Components/ground_friction.cpp
    Source/Components/steps_on_tiles.cpp
    Source/Components/spawns_sea.cpp
    Source/Components/AI/looks_at_target.cpp
    Source/Components/AI/moves_towards_target.cpp
    Source/Components/AI/aggressive_targeting.cpp
    Source/Tiles/water.cpp
    Source/Tiles/grass.cpp
    Source/Tiles/cliff.cpp
    Source/Tiles/ice.cpp
    Source/Tiles/Util/levelgen.cpp
    Source/Tiles/Util/tile_loader.cpp
    Source/Tiles/Base/tile.cpp
    Source/Tiles/Other/tilemap.cpp
    Source/Light/light.cpp
    Source/States/handler.cpp
    Source/States/test.cpp
    Source/States/state_base.cpp
    Source/Entities/player.cpp
    Source/Entities/Bases/enemy_mob.cpp
    Source/Entities/Bases/mob.cpp
    Source/Entities/Bases/sf_entity.cpp
    Source/Entities/Enemies/zombie.cpp
    Source/Entities/Enemies/shark.cpp
)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

#Define the executable
add_executable(
    ${PROJECT_NAME} 
    ${SOURCES} 
)
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})