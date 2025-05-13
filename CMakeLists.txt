cmake_minimum_required(VERSION 3.14)
project(MyQtApp)

set(CMAKE_CXX_STANDARD 17)

# Set your Qt installation path
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(MyQtApp main.cpp MyWidget.cpp)

target_link_libraries(MyQtApp PRIVATE Qt6::Widgets)
