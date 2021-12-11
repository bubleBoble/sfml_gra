cmake_minimum_required(VERSION 3.0.0)
project(001_abc_ct VERSION 0.1.0)



configure_file(include/config.h config.h)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# kompiluje pojedyńczo
add_executable(OUTPUT
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)
# ------------------------- kozak

# # kompiluje wszystkie pliki cpp z src
# FILE(GLOB source_files ${CMAKE_SOURCE_DIR}/src/*.cpp)

# add_executable(OUTPUT
#     ${source_files}
# )
# # ------------------------- debil

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
