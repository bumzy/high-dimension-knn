# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_TRAVERSAL_SRCS 变量
aux_source_directory(. DIR_TRAVERSAL_SRCS)
# 生成链接库
add_library (traversal ${DIR_TRAVERSAL_SRCS})
target_link_libraries(traversal common)
set(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall")
