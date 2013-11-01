cmake_minimum_required (VERSION 2.6)
set (CMAKE_BACKWARDS_COMPATIBILITY 2.6)

set(PLUGIN_NAME npfdemo)

set(FRWK_DIR ${PROJECT_SOURCE_DIR}/frmwk)
set(SRC_FILES ${FRWK_DIR}/npfrmwk.h ${FRWK_DIR}/npfrmwk_entry.cpp ${FRWK_DIR}/npfrmwkbase.h )
file(GLOB_RECURSE SUB_SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    [^.]*.cpp
    [^.]*.h
    [^.]*.def
    [^.]*.rc
)
list(APPEND SRC_FILES ${SUB_SRC_FILES})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/${PLUGIN_NAME})
add_library(${PLUGIN_NAME} SHARED ${SRC_FILES})
