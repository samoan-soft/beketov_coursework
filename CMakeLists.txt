cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME Drawing_fractals)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED on)

find_package(Doxygen)

option(BUILD_DOCUMENTATION "Create and install documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if(DOXYGEN_FOUND)

	set(DOXYGEN ${CMAKE_SOURCE_DIR}/documentation/Doxyfile.in)
	
    message("Doxygen build started")
	
	add_custom_target(
		docs ALL
		COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN}
		COMMENT "Generating documentation with Doxygen"
		VERBATIM
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/documentation
	)
    message("Doxygen build completed")

endif()

include_directories(sources)

set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}")

install(FILES 
	${CMAKE_SOURCE_DIR}/SFML-2.4.2/bin/sfml-graphics-2.dll
	${CMAKE_SOURCE_DIR}/SFML-2.4.2/bin/sfml-system-2.dll
	${CMAKE_SOURCE_DIR}/SFML-2.4.2/bin/sfml-window-2.dll 
	DESTINATION ${CMAKE_SOURCE_DIR}/programm
	CONFIGURATIONS Release)

install(FILES 
	${CMAKE_SOURCE_DIR}/SFML-2.4.2/bin/sfml-graphics-d-2.dll
	${CMAKE_SOURCE_DIR}/SFML-2.4.2/bin/sfml-system-d-2.dll
	${CMAKE_SOURCE_DIR}/SFML-2.4.2/bin/sfml-window-d-2.dll 
	DESTINATION ${CMAKE_SOURCE_DIR}/programm
	CONFIGURATIONS Debug)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/textures 
	DESTINATION ${CMAKE_SOURCE_DIR}/programm)

add_subdirectory(sources)

install(TARGETS ${PROJECT_NAME} 
	DESTINATION ${CMAKE_SOURCE_DIR}/programm)
