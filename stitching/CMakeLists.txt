cmake_minimum_required(VERSION 2.8)
project( map_stitcher )
find_package( OpenCV REQUIRED )
add_executable( map_stitcher map_stitcher.cpp )
target_link_libraries( map_stitcher ${OpenCV_LIBS} )
