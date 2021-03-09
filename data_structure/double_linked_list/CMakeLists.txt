# CMakeのバージョン指定
cmake_minimum_required(VERSION 3.19)

# プロジェクトの設定
project(
    dllist_lib 
    VERSION 1.0.0
    DESCRIPTION "Double Linked List library"
    LANGUAGES C
    )

# C言語の仕様のバージョン
set(CMAKE_C_STANDARD 99)

# ライブラリの作成方法
add_library(dllist STATIC ./src/double_linked_list.c)

# インクルードディレクトリの指定
target_include_directories(dllist PUBLIC ./include)

# ライブラリのプロパティ設定
set_target_properties(
    dllist
    PROPERTIES
    VERSION ${PROJECT_VERSION}
    )
