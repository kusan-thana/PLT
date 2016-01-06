cmake_minimum_required (VERSION 2.8)
project (FANTASY_WORLD)
include_directories ("${PROJECT_SOURCE_DIR}/src")

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
IF(CMAKE_COMPILER_IS_GNUCC)
	SET(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -std=c11   -g")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")
ENDIF(CMAKE_COMPILER_IS_GNUCC)


# jsoncpp
include_directories ("${PROJECT_SOURCE_DIR}/lib/extern/jsoncpp-0.10.5/dist")
file(GLOB jsoncpp_sources "${PROJECT_SOURCE_DIR}/lib/extern/jsoncpp-0.10.5/dist/jsoncpp.cpp")

# Main
file(GLOB_RECURSE mainSourcesClient src/common/*.cpp src/client/*.cpp)

# add the executable
add_executable (FantasyWorldClient ${mainSourcesClient})

# Main
file(GLOB_RECURSE mainSourcesServer src/common/*.cpp src/server/*.cpp)

# add the executable
add_executable (FantasyWorldServer ${mainSourcesServer})

#libmicrohttpd
include_directories ("${PROJECT_SOURCE_DIR}/lib/extern/libmicrohttpd/include")
target_link_libraries(FantasyWorldClient "${PROJECT_SOURCE_DIR}/lib/extern/libmicrohttpd/lib/libmicrohttpd.so")
target_link_libraries(FantasyWorldServer "${PROJECT_SOURCE_DIR}/lib/extern/libmicrohttpd/lib/libmicrohttpd.so")


#find_package (Threads)
#target_link_libraries (FantasyWorld ${CMAKE_THREAD_LIBS_INIT})

# SFML
set(SFML_ROOT "/usr")
set(CMAKE_MODULE_PATH "${SFML_ROOT}/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 COMPONENTS ./ru./rungraphics window system audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(FantasyWorldClient ${SFML_LIBRARIES})
  target_link_libraries(FantasyWorldServer ${SFML_LIBRARIES})
endif()

set(SFML_ROOT "/usr/lsa")
set(CMAKE_MODULE_PATH "${SFML_ROOT}/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 COMPONENTS graphics window system audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(FantasyWorldClient ${SFML_LIBRARIES})
  target_link_libraries(FantasyWorldServer ${SFML_LIBRARIES})
endif()




