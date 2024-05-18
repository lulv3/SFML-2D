cmake_minimum_required(VERSION 3.10)
project(Platformer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# SFML
set(SFML_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party/SFML")
set(SFML_INCLUDE_DIR "${SFML_ROOT_DIR}/include")
set(SFML_LIBRARY_DIR "${SFML_ROOT_DIR}/lib")
set(SFML_DIR "${SFML_ROOT_DIR}/lib/cmake/SFML")

# ImGui
set(IMGUI_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui")
set(IMGUI_INCLUDE_DIR "${IMGUI_ROOT_DIR}")
file(GLOB IMGUI_HEADERS "${IMGUI_ROOT_DIR}/*.h")
file(GLOB IMGUI_SOURCES "${IMGUI_ROOT_DIR}/*.cpp")

# Find SFML
find_package(SFML COMPONENTS graphics REQUIRED)

# Game
set(GAME_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(GAME_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB GAME_HEADERS ${GAME_INCLUDE_DIR}/*.h)
file(GLOB GAME_SOURCES ${GAME_SRC_DIR}/*.cpp)

# Engine
set(ENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Engine/include)
set(ENGINE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Engine/src)
file(GLOB ENGINE_HEADERS ${ENGINE_INCLUDE_DIR}/*.h)
file(GLOB ENGINE_SOURCES ${ENGINE_SRC_DIR}/*.cpp)

# Include directories
include_directories(${SFML_INCLUDE_DIR} ${IMGUI_INCLUDE_DIR} ${GAME_INCLUDE_DIR} ${ENGINE_INCLUDE_DIR})

# Executable
add_executable(Platformer ${GAME_HEADERS} ${GAME_SOURCES} ${ENGINE_SOURCES} ${IMGUI_HEADERS} ${IMGUI_SOURCES})

# Link gegen die SFML-Bibliotheken
target_link_libraries(Platformer sfml-graphics sfml-window sfml-system openGL32)

# Definiere den Quellpfad für die Assets
set(ASSETS_SOURCE_DIR ${CMAKE_SOURCE_DIR}/Assets)

# Definiere den Zielordner im Buildverzeichnis
set(ASSETS_DEST_DIR ${CMAKE_BINARY_DIR}/)

# Kopiere die Assets während des Buildprozesses
file(COPY ${ASSETS_SOURCE_DIR} DESTINATION ${ASSETS_DEST_DIR})

# Kopiere die SFML-DLLs in den Ausgabeordner beim Build
add_custom_command(TARGET Platformer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${SFML_ROOT_DIR}/bin $<TARGET_FILE_DIR:Platformer>)

# Ausblenden der Konsole beim Starten
#if(WIN32)
#    set_target_properties(Platformer PROPERTIES WIN32_EXECUTABLE true)
#endif()
