cmake_minimum_required(VERSION 3.1)

project(libvas)

add_library(libvas STATIC src/vas.c)

target_include_directories(libvas PUBLIC include)
