# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_E2LSH_SRCS 变量
aux_source_directory(. DIR_E2LSH_SRCS)
# 生成链接库
add_library (e2lsh ${DIR_E2LSH_SRCS})
