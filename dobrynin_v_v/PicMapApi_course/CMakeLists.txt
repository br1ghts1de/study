cmake_minimum_required(VERSION 2.8)

if ( NOT DEFINED OpenCV_INCLUDE_DIRS )
  find_package( OpenCV REQUIRED )
endif()

project(PicMapApi)

include_directories(
  ${CMAKE_SOURCE_DIR}
  ${OpenCV_INCLUDE_DIRS}
)

set(PicMapApi_public_HDRS
  PicMapApi.h
  xxhash64.h
)

set(PicMapApi_SRCS PicMapApi.cpp
)

add_library(PicMapApi ${PicMapApi_public_HDRS} ${PicMapApi_SRCS})

target_link_libraries(PicMapApi ${OpenCV_LIBS})

