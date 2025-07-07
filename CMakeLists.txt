cmake_minimum_required(VERSION 3.20)
project(game C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-O2 -Wall -Wextra")

# Find SDL2, SDL2_image, SDL2_mixer cross-platform
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)

# Include SDL headers
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})

# Your source files
file(GLOB_RECURSE VIEW_SRCS "src/views/*.c" "src/views/MainHelpers/*.c")
file(GLOB MAIN_SRCS "src/*.c" "src/ScoreRenderer/*.c")

list(REMOVE_ITEM MAIN_SRCS ${VIEW_SRCS})

add_executable(game ${MAIN_SRCS} ${VIEW_SRCS})

# Link SDL libraries
target_link_libraries(game SDL2::SDL2 SDL2_image::SDL2_image SDL2_mixer::SDL2_mixer)