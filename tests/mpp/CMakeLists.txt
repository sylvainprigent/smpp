### CMakeLists.txt --- 
##
######################################################################
## 
### Commentary: 
## 
######################################################################
## 
### Change log:
## 
######################################################################
enable_testing()

project(smppTest)

enable_testing()

## #################################################################
## Input
## #################################################################

set(${PROJECT_NAME}_MAIN_SOURCES
  TestMppAlgoGrad.cpp
  TestMppInteraction2DNoOverlap.cpp
  TestMppSilhouette.cpp
  TestMppShapeCircle.cpp
)

## ###################################################################
## Configure file
## ###################################################################

if(EXISTS ${PROJECT_SOURCE_DIR}/imagesTest/cell.tif)
  set(CELL ${PROJECT_SOURCE_DIR}/imagesTest/cell.tif)
endif()

if(EXISTS ${PROJECT_SOURCE_DIR}/imagesTest/cell_bm.tif)
  set(CELLBM ${PROJECT_SOURCE_DIR}/imagesTest/cell_bm.tif)
endif()

if(EXISTS ${PROJECT_SOURCE_DIR}/smppTestConfig.h.in)
  configure_file(smppTestConfig.h.in ${CMAKE_BINARY_DIR}/smppTestConfig.h)
endif()

## #################################################################
## Build rules
## #################################################################

SET(TESTS "")

foreach (test ${${PROJECT_NAME}_MAIN_SOURCES})
  get_filename_component(TName ${test} NAME_WE)

  add_executable(${TName} ${test})
  target_link_libraries(${TName} smpp ${SL_LIBRARIES})

  add_test(${TName} ${EXECUTABLE_OUTPUT_PATH}/${TName})

  set(TEST ${TESTS} ${EXECUTABLE_OUTPUT_PATH}/${TName})
endforeach()

add_custom_target(testbioimagebase COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS ${TESTS})

## #################################################################
## Source file layout in development environments like Visual Studio
## #################################################################
SOURCE_GROUP("Header Files" REGULAR_EXPRESSION .*\\.h\$)
SOURCE_GROUP("Source Files" REGULAR_EXPRESSION .*\\.cpp\$)
