cmake_minimum_required(VERSION 3.26)
project(ProyectoLaboratorio_RG)

set(CMAKE_CXX_STANDARD 14)

if(MINGW)
        link_libraries(ws2_32 wsock32)
endif()

include_directories(./src/lib/binarySearch)
include_directories(./src/lib/linearSearch)
include_directories(./src/lib/quicksort)

add_executable(ProyectoLaboratorio_RG ./src/main.cpp)

add_subdirectory(./src/lib/binarySearch)
add_subdirectory(./src/lib/linearSearch)
add_subdirectory(./src/lib/quicksort)

target_link_directories(ProyectoLaboratorio_RG
        PRIVATE binarySearch
        PRIVATE linearSearch
        PRIVATE quicksort)

target_link_libraries(ProyectoLaboratorio_RG
        PRIVATE binarySearch
        PRIVATE linearSearch
        PRIVATE quicksort)