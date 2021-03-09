#CMakeのバージョン
cmake_minimum_required(VERSION 3.19)

# プロジェクトの設定
project(
    sort_lib
    VERSION 1.0.0
    DESCRIPTION "様々なソートアルゴリズムを素朴に実装したライブラリ"
    LANGUAGES C
)

# C言語の仕様のバージョン
set(CMAKE_C_STANDARD 99)

# ターゲットの設定
add_library(sort STATIC ./src/sort.c)

# リンクするライブラリの指定
target_link_libraries(sort INTERFACE heap util)

# インクルードディレクトリの設定
target_include_directories(
    sort
    PUBLIC 
    ./include/
    ../../data_structure/heap/include/
    ../../util/include/
)

# ライブラリのプロパティ設定
set_target_properties(sort PROPERTIES VERSION ${PROJECT_VERSION})
