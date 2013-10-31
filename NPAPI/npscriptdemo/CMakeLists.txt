cmake_minimum_required (VERSION 2.6)
set (CMAKE_BACKWARDS_COMPATIBILITY 2.6)

set(PLUGIN_NAME npscriptdemo)
#set(Boost_ROOT C:/boost_1_50_0)
#set(Boost_LIBRARIES ${Boost_ROOT}/stage/lib)

set(FRWK_DIR ${PROJECT_SOURCE_DIR}/frmwk)
set(SRC_FILES ${FRWK_DIR}/npfrmwk.h ${FRWK_DIR}/npfrmwk_entry.cpp ${FRWK_DIR}/npfrmwkbase.h )
file(GLOB_RECURSE SUB_SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    [^.]*.cpp
    [^.]*.h
    [^.]*.def
    [^.]*.rc
)
add_definitions(-DENABLE_SCRIPT_OBJECT)
#include_directories(${Boost_ROOT})
#link_directories(${Boost_LIBRARIES})

list(APPEND SRC_FILES ${SUB_SRC_FILES})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/${PLUGIN_NAME})
add_library(${PLUGIN_NAME} SHARED ${SRC_FILES})

