add_library(geometry SHARED vectors.hpp calculus.cpp calculus.hpp)
target_include_directories(geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
