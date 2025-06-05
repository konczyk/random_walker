cmake_minimum_required(VERSION 3.30)
project(random_walker C)

set(CMAKE_C_STANDARD 23)

option(VENDOR "Use vendor libraries" OFF)

if(VENDOR)
    add_subdirectory(vendor/SDL3 EXCLUDE_FROM_ALL)
else()
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

set(SOURCES
        main.c
        init.c
        loop.c
        walker.c
)

list(TRANSFORM SOURCES PREPEND "src/")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
