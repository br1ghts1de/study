cmake_minimum_required(VERSION 2.8)

project(PicMapApi)

find_package(OpenCV)

include_directories(${CMAKE_SOURCE_DIR}
${OpenCV_INCLUDE_DIRS})

set(PicMapApi_public_HDRS PicMapApi.h xxhash64.h)

set(PicMapApi_SRCS PicMapApi.cpp PicMapApi_test.cpp)

add_executable(PicMapApi ${PicMapApi_public_HDRS} ${PicMapApi_SRCS})

target_link_libraries(PicMapApi ${OpenCV_LIBS})
