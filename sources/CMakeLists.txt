
set(SOURCE_FILES 
	menu.h 
	menu.cpp
        mandelbrot.h
	mandelbrot.cpp
        tree.h
	tree.cpp
        sierpinski.h
        sierpinski.cpp
        main.cpp )

set(SFML_ROOT ${CMAKE_SOURCE_DIR}/SFML-2.4.2)

set(SFML_STATIC_LIBRARIES FALSE)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/SFML-2.4.2/cmake/Modules")

find_package(SFML REQUIRED COMPONENTS audio graphics window system)

include_directories(${SFML_INCLUDE_DIR})

add_executable (${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

