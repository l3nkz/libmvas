cmake_minimum_required(VERSION 3.1)

project(libmvas)

# Define where to save the final libraries and binaries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# All Targets and their properties
add_library(mvas STATIC src/vas.c src/segment.c)
target_include_directories(mvas PUBLIC include)

# Installing targets
install(TARGETS mvas
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/mvas DESTINATION include)
