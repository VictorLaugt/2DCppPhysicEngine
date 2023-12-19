add_library(geometry STATIC vectors.cpp calculus.cpp)
target_include_directories(geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
