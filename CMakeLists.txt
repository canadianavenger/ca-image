cmake_minimum_required(VERSION 3.21)

# set the project name
project(ca-image)

# set the output directories
set (ProdDir "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${ProdDir}/lib/static")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${ProdDir}/lib/shared")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ProdDir}/bin")

include_directories(
    "."
    "include"
)

set (palette 
    "src/pal-bits.c"
    "src/pal-order.c"
    "src/pal-565.c"
)

set (image 
    "src/image.c"
)

# consolidate the groups
set (sources 
    ${image}
    ${palette}
)

# generate the consolidated library
add_library (${PROJECT_NAME} ${sources})

