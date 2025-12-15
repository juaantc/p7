add_library(persons persons.cc persons.h)
target_include_directories(persons PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(irole-main irole-main.cc)
target_link_libraries(irole-main PRIVATE persons)
	