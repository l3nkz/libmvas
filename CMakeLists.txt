cmake_minimum_required(VERSION 3.1)

project(libmvas)

# Define where to save the final libraries and binaries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# All Targets and their properties
add_library(mvas SHARED src/vas.c)
target_include_directories(mvas PUBLIC include)

set_property(TARGET mvas PROPERTY VERSION "0.1")
set_property(TARGET mvas PROPERTY SOVERSION 1 )

# Installing targets
install(TARGETS mvas
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/mvas DESTINATION include)
