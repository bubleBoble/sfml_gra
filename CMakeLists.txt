cmake_minimum_required(VERSION 3.0.0)
project(grainf_copy VERSION 0.1.0)



configure_file(include/config.h config.h)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# kompiluje pojedyńczo
add_executable(OUTPUT
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/Game.cpp
    ${CMAKE_SOURCE_DIR}/src/Enemy.cpp
    ${CMAKE_SOURCE_DIR}/src/Hud.cpp
    ${CMAKE_SOURCE_DIR}/src/Player.cpp
    ${CMAKE_SOURCE_DIR}/src/Animation.cpp
    ${CMAKE_SOURCE_DIR}/src/Bullet.cpp
    ${CMAKE_SOURCE_DIR}/src/Mainmenu.cpp
    ${CMAKE_SOURCE_DIR}/src/Startscreen.cpp
    ${CMAKE_SOURCE_DIR}/src/Highscores.cpp

    # ${CMAKE_SOURCE_DIR}/src/Fireball.cpp
    # ${CMAKE_SOURCE_DIR}/src/FireballAnimation.cpp
    # ${CMAKE_SOURCE_DIR}/src/Spawner.cpp
)


# ---------------------------

# # kompiluje wszystkie pliki cpp z src
# FILE(GLOB source_files ${CMAKE_SOURCE_DIR}/src/*.cpp)

# add_executable(OUTPUT
#     ${source_files}
# )
# # ------------------------- 

add_custom_target(
    run COMMAND ..\\bin\\OUTPUT.exe
)

target_include_directories(OUTPUT PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(OUTPUT PROPERTIES
    INSTALL_RPATH
    ${CMAKE_INSTALL_PREFIX}/lib
)

target_link_libraries(OUTPUT sfml-graphics sfml-audio)

set_target_properties( OUTPUT PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
