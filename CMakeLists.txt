cmake_minimum_required(VERSION 3.26)
project(MALL)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        main.cpp
        ARCHITECTURE/Item/Item.cpp
        ARCHITECTURE/Date/Date.cpp
        ARCHITECTURE/Shop/Shop.cpp
        ARCHITECTURE/ShoppingCart/ShoppingCart.cpp
        ARCHITECTURE/Brand/Brand.cpp
        ARCHITECTURE/Mall/Mall.cpp
)

# Create an executable target named "MALL" from the source files
add_executable(MALL ${SOURCES})

# Set the include directories for this target
target_include_directories(MALL PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Find and link GLFW
find_package(glfw3 REQUIRED)
target_link_libraries(MALL PRIVATE glfw)

# Find and link OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(MALL PRIVATE OpenGL::GL)

# Include GLM
include_directories(/opt/homebrew/Cellar/glm/0.9.9.8)

# Set ASSIMP_ROOT
set(ASSIMP_ROOT "/opt/homebrew/Cellar/assimp/5.2.5" CACHE PATH "Path to Assimp installation directory")

# Find and link Assimp
find_package(assimp REQUIRED HINTS ${ASSIMP_ROOT})
target_include_directories(MALL PRIVATE ${ASSIMP_INCLUDE_DIRS})
target_link_libraries(MALL PRIVATE ${ASSIMP_LIBRARIES})

# Find and link Freetype
find_package(Freetype REQUIRED)
target_link_libraries(MALL PRIVATE Freetype::Freetype)

# Include IMGUI (Make sure to set IMGUI_INCLUDE_DIRS and IMGUI_LIBRARIES)
include_directories(libraries)
target_link_libraries(MALL PRIVATE ${IMGUI_LIBRARIES})