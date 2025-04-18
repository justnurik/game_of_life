cmake_minimum_required(VERSION 3.20)

project(game_of_live VERSION 0.1.0 LANGUAGES C CXX)

SET(CMAKE_CXX_FLAGS "-std=c++20")
# SET(CMAKE_CXX_FLAGS "-fsanitize=address")
# SET(CMAKE_CXX_FLAGS "rpath-link ")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.6.1 COMPONENTS system window graphics audio REQUIRED)


add_subdirectory(src)

add_executable(run main.cpp)

include_directories(run PUBLIC lib/sfml/SFML-2.6.1/include
                        PUBLIC lib/sfml/SFML-2.6.1/lib)

target_link_libraries(graphicslib PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)

target_link_libraries(run PUBLIC sfeMovie)
target_link_libraries(run PUBLIC sfml-graphics sfml-window sfml-system)
target_link_libraries(run PUBLIC graphicslib
                           PUBLIC datalib
                           PUBLIC templib
                           PUBLIC gamelib
                           PUBLIC game)

# Install sfeMovies packages
install(DIRECTORY ${CMAKE_SOURCE_DIR}/sfeMovie/lib/ DESTINATION lib/sfeMovieLib/)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/sfeMovie/include/ DESTINATION lib/sfeMovieInclude/) 


