cmake_minimum_required(VERSION 3.0)

project(libs LANGUAGES C)

add_library ( ${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PRIVATE move.c move.h sdlrender.c sdlrender.h snake.c snake.h)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 SDL2main)

target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

install(FILES move.h DESTINATION include)
install(FILES sdlrender.h DESTINATION include)
install(FILES snake.h DESTINATION include)
