cmake_minimum_required(VERSION 3.15)
project(dogGame01)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "/home/dev/SFML/lib/cmake/SFML")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lGL")
set(SFML_INCLUDE_DIR /home/dev/SFML/include)


find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(/home/dev/SFML/include)


add_executable(dogGame01 src/main.cpp)
set_target_properties(dogGame01 PROPERTIES LINK_FLAGS "-no-pie")

target_link_libraries(dogGame01 
                      PRIVATE
                      sfml-graphics 
                      sfml-window 
                      sfml-system 
                      sfml-audio)
