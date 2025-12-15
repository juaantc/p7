add_library(counter counter.cc counter.h)
target_include_directories(counter PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(counter-main counter-main.cc)
target_link_libraries(counter-main PRIVATE counter)