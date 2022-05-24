cmake_minimum_required(VERSION 3.0)

project(SNAKE LANGUAGES C)

add_executable ( ${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PRIVATE main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 SDL2main)

target_link_libraries(${PROJECT_NAME} PRIVATE libs)
add_subdirectory(libs)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
