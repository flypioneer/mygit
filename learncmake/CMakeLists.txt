# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目名称
project (Demo)

# 查找当前目录下的所有源文件，并将名称保存到　DIR_SRCS 变量
aux_source_directory(. SRC_DIRS)



# 指定生成目标，使用main.cpp生成可执行文件Demo
add_executable(Demo ${SRC_DIRS})