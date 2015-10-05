cmake_minimum_required (VERSION 2.6.4)
project (FANTASY_WORLD)

#include_directories ("${PROJECT_SOURCE_DIR}/lib")
#add_subdirectory (lib)
include_directories ("${PROJECT_SOURCE_DIR}/src")
add_subdirectory (src)


# add the executable
add_executable (../bin/FantasyWorld src/fantasyWorld.cpp)
target_link_libraries (../bin/FantasyWorld src)
