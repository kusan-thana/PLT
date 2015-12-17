cmake_minimum_required (VERSION 2.6.4)
project (FANTASY_WORLD)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


file(GLOB_RECURSE mainSources src/*.cpp)

# add the executable
add_executable (FantasyWorld ${mainSources})



#find_package (Threads)
#target_link_libraries (FantasyWorld ${CMAKE_THREAD_LIBS_INIT})

# SFML
set(SFML_ROOT "/usr")
set(CMAKE_MODULE_PATH "${SFML_ROOT}/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 COMPONENTS ./ru./rungraphics window system audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(FantasyWorld ${SFML_LIBRARIES})
endif()

set(SFML_ROOT "/usr/lsa")
set(CMAKE_MODULE_PATH "${SFML_ROOT}/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 COMPONENTS graphics window system audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(FantasyWorld ${SFML_LIBRARIES})
endif()




