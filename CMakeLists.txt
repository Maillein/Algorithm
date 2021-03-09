cmake_minimum_required(VERSION 3.19)

# プロジェクト名
project(Algorithm C)
# C言語の仕様のバージョン
set(CMAKE_C_STANDARD 99)

# ライブラリのディレクトリ
add_subdirectory(./util) # ユーティリティ 
add_subdirectory(./data_structure/heap) # ヒープ
add_subdirectory(./data_structure/double_linked_list) # 双方向リスト
add_subdirectory(./algorithm/sort) # ソート

# mainという実行ファイルをmain.cppから作成
add_executable(main main.c)

# リンクするライブラリの指定
target_link_libraries(main util heap sort dllist)
