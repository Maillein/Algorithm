# CMakeのバージョン指定
cmake_minimum_required(VERSION 3.19)

# プロジェクトの設定
project(
    heap_lib
    VERSION 1.0.0
    DESCRIPTION "Heap library"
    LANGUAGES C
    )

# C言語の仕様のバージョン
set(CMAKE_C_STANDARD 99)

# ライブラリの作成方法
# add_library(heap STATIC ./src/heap.c ../../util/src/util.c)
add_library(heap STATIC ./src/heap.c)

# リンクするライブラリの指定
target_link_libraries(heap INTERFACE util)

# インクルードディレクトリの指定
target_include_directories(heap PUBLIC ./include/ ../../util/include/)

# ライブラリのプロパティ設定
set_target_properties(
    heap
    PROPERTIES
    VERSION ${PROJECT_VERSION}
    )
