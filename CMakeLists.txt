cmake_minimum_required ( VERSION 2.8)
project(high-dimension-knn)
include_directories(./ ./common ./e2lsh ./rtree ./traversal)
aux_source_directory(. DIR_SRCS)
add_executable(test_all ${DIR_SRCS})
target_link_libraries(test_all common rtree traversal)

# 添加子目录
add_subdirectory(common)
# add_subdirectory(e2lsh)
add_subdirectory(rtree)
add_subdirectory(traversal)

set(CMAKE_CXX_COMPILER "g++" )
set(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall")

set(CMAKE_CXX_FLAGS_DEBUG "-O0" )
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG " )
