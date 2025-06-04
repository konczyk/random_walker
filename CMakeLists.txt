cmake_minimum_required(VERSION 3.30)
project(random_walker C)

set(CMAKE_C_STANDARD 23)

add_subdirectory(vendor/SDL3-3.2.16 EXCLUDE_FROM_ALL)

set(SOURCES
        main.c
        init.c
        loop.c
        walker.c
)

list(TRANSFORM SOURCES PREPEND "src/")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
