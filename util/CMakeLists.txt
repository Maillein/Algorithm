# CMakeのバージョン指定
cmake_minimum_required(VERSION 3.19)

# プロジェクトの設定
project(
    util_lib
    VERSION 1.0.0
    DESCRIPTION "Util library"
    LANGUAGES C
    )

# C言語の仕様のバージョン
set(CMAKE_C_STANDARD 99)

# ライブラリの作成方法
# add_library(util STATIC ./src/util.c)
add_library(util STATIC ./src/util.c)

# インクルードディレクトリの指定
target_include_directories(util INTERFACE ./include)

# ライブラリのプロパティ設定
set_target_properties(
    util
    PROPERTIES
    VERSION ${PROJECT_VERSION}
    )
