cmake_minimum_required(VERSION 3.1)

project(libvas)

add_library(mvas STATIC src/vas.c src/segment.c)

set_target_properties(mvas PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
)

target_include_directories(mvas PUBLIC include)
