# Written to work with cmake 2.6
cmake_minimum_required (VERSION 2.6)
set (CMAKE_BACKWARDS_COMPATIBILITY 2.6)

project(NPAPI_Plugins)

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/frmwk)

add_subdirectory(npscriptdemo)
add_subdirectory(npfdemo)
