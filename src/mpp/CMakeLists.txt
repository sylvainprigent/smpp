############################################################
#
# $Id$
#
# Copyright (c) smpp 2020
#
# AUTHOR:
# Sylvain Prigent
# 

# Project name
project(smpp)

## #################################################################
## Define files
## #################################################################

SET(SRC_FILES
  MppAlgorithm2D.cpp
  MppAlgorithm2DSBCR.cpp
  MppColor.cpp
  MppDataTerm2D.cpp
  MppDataTerm2DBhattacharyya.cpp
  MppDictionary2D.cpp
  MppDictionary2DCircle.cpp
  MppDraw2D.cpp
  MppInteraction2D.cpp
  MppInteraction2DNoOverlap.cpp
  MppPoint.cpp
  MppRand.cpp
  MppShape2D.cpp
  MppShapeCircle.cpp
  MppSilhouette2D.cpp
  SImage2D.cpp
)

SET(HEADERS_FILES
  MppAlgorithm2D.h
  MppAlgorithm2DSBCR.h
  MppColor.h
  MppDataTerm2D.h
  MppDataTerm2DBhattacharyya.h
  MppDictionary2D.h
  MppDictionary2DCircle.h
  MppDraw2D.h
  MppInteraction2D.h
  MppInteraction2DNoOverlap.h
  MppPoint.h
  MppRand.h
  MppShape2D.h
  MppShapeCircle.h
  MppSilhouette2D.h
  SImage2D.h
)
  
## #################################################################
## Library target
## #################################################################

add_library(${PROJECT_NAME} ${SRC_FILES} ${HEADERS_FILES})

target_link_libraries(${PROJECT_NAME})

## #################################################################
## Export header file
## #################################################################

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

generate_export_header(${PROJECT_NAME}
  EXPORT_FILE_NAME "${PROJECT_NAME}Export.h")

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different "${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Export.h" "${CMAKE_BINARY_DIR}"
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different "${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Export.h" "${CMAKE_BINARY_DIR}/${PROJECT_NAME}Export")
