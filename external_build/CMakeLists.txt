cmake_minimum_required(VERSION 2.6)

project(test_dll_client)

INCLUDE_DIRECTORIES(externalBuild)
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/externalBuild)

add_executable(test_dll_client
main.cxx)

TARGET_LINK_LIBRARIES(
 test_dll_client
 test_dll
)
#add_library(
#test_dll
#common.h
#common.cxx
#)