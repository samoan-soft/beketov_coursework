cmake_minimum_required(VERSION 3.0.2)

project(Mandelbrot)

find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

set(SOURCES
   menu.h
   menu.cpp
   mandelbrot.h
   mandelbrot.cpp
   main.cpp
)

add_executable(Mandelbrot ${SOURCES})

target_link_libraries(Mandelbrot sfml-audio sfml-graphics sfml-window sfml-system)

set_target_properties(Mandelbrot PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})