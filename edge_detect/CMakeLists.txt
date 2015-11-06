cmake_minimum_required(VERSION 2.8)
project( edge_detect )
find_package( OpenCV REQUIRED )
add_executable( edge_detect main.cpp )
target_link_libraries( edge_detect ${OpenCV_LIBS} )

