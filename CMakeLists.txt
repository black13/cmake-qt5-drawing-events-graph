cmake_minimum_required(VERSION 3.10)
project(graph_project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


# Find required packages
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Boost REQUIRED)
#find_package(nlohmann_json REQUIRED)

# Include Boost
set(BOOST_ROOT "/opt/boost")


# Include directories for Boost and nlohmann_json
include_directories(${Boost_INCLUDE_DIRS})
#include_directories(${nlohmann_json_INCLUDE_DIRS})
include_directories(/opt/json)
# Add your source files
set(SOURCES
    main.cpp
    GraphicsScene.cpp
    GraphicsScene.h
    EdgeObject.cpp
    EdgeObject.h
    VertexObject.cpp
    VertexObject.h
)

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries to your project
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
