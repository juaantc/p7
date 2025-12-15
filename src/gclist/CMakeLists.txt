add_library(gclist gclist.cc gclist.h)
target_link_libraries(gclist PUBLIC persons catalog stage)
target_include_directories(gclist PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(gclist-main1 gclist-main1.cc)
target_link_libraries(gclist-main1 PRIVATE gclist)

add_executable(gclist-main2 gclist-main2.cc)
target_link_libraries(gclist-main2 PRIVATE gclist)

add_executable(gclist-main3 gclist-main3.cc)
target_link_libraries(gclist-main3 PRIVATE gclist)