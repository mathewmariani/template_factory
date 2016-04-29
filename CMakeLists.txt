cmake_minimum_required (VERSION 2.8)
project (template_factory)

# version number
set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)

# include the subdirectory containing our libs
include_directories (src)

# add files to project
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${PROJECT_SOURCE_DIR}/src/*.h")

add_executable (template_factory ${SOURCES} ${HEADERS})
