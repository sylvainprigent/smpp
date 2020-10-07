############################################################
#
# $Id$
#
# Copyright (c) SMpp 2020
#
# AUTHOR:
# Sylvain Prigent
# 

## #################################################################
## Doxygen
## #################################################################

find_package(Doxygen QUIET)
if(${DOXYGEN_FOUND})
  set(smpp_USE_DOXYGEN 1)
endif(${DOXYGEN_FOUND})

if(${SL_USE_OPENMP})
  find_package(OpenMP REQUIRED)
endif(${SL_USE_OPENMP})  

## #################################################################
## SImage
## #################################################################
find_package (simage REQUIRED)
if ( simage_FOUND )
  message(STATUS "Using simage")
  set (SL_INCLUDE_DIRS ${SL_INCLUDE_DIRS} ${simage_INCLUDE_DIRS})
  set (SL_LIBRARY_DIRS ${SL_LIBRARY_DIRS} ${simage_LIBRARY_DIRS})
  set (SL_LIBRARIES ${SL_LIBRARIES} ${simage_LIBRARIES})
  message(STATUS "simage_LIBRARY_DIRS=" ${simage_LIBRARY_DIRS}) 
  set(smpp_HAVE_simage 1)
else( simage_FOUND )
  message(STATUS "NOT Using simage")
endif( simage_FOUND )

## #################################################################
## SImageIO and scli needed for tool
## #################################################################
if (${smpp_BUILD_TOOLS})

  find_package (score REQUIRED)
  if ( score_FOUND )
    message(STATUS "Using score")
    set (SL_INCLUDE_DIRS ${SL_INCLUDE_DIRS} ${score_INCLUDE_DIRS})
    set (SL_LIBRARY_DIRS ${SL_LIBRARY_DIRS} ${score_LIBRARY_DIRS})
    set (SL_LIBRARIES ${SL_LIBRARIES} ${score_LIBRARIES})
    message(STATUS "score_LIBRARY_DIRS=" ${score_LIBRARY_DIRS}) 
    set(smpp_HAVE_score 1)
  else( score_FOUND )
    message(STATUS "NOT Using score")
  endif( score_FOUND )

  find_package (simageio REQUIRED)
  if ( simageio_FOUND )
    message(STATUS "Using SImageIO")
    set (SL_INCLUDE_DIRS ${SL_INCLUDE_DIRS} ${simageio_INCLUDE_DIRS})
    set (SL_LIBRARY_DIRS ${SL_LIBRARY_DIRS} ${simageio_LIBRARY_DIRS})
    set (SL_LIBRARIES ${SL_LIBRARIES} ${simageio_LIBRARIES})
    message(STATUS "simageio_LIBRARY_DIRS=" ${simageio_LIBRARY_DIRS}) 
    set(smpp_HAVE_SIMAGEIO 1)
  else( simageio_FOUND )
    message(STATUS "NOT Using SImageIO")
  endif( simageio_FOUND )

  find_package (scli REQUIRED)
  if ( scli_FOUND )
    message(STATUS "Using scli")
    set (SL_INCLUDE_DIRS ${SL_INCLUDE_DIRS} ${scli_INCLUDE_DIRS})
    set (SL_LIBRARY_DIRS ${SL_LIBRARY_DIRS} ${scli_LIBRARY_DIRS})
    set (SL_LIBRARIES ${SL_LIBRARIES} ${scli_LIBRARIES})
    message(STATUS "scli_LIBRARY_DIRS=" ${scli_LIBRARY_DIRS}) 
    set(smpp_HAVE_scli 1)
  else( scli_FOUND )
    message(STATUS "NOT Using scli")
  endif( scli_FOUND )


  find_package (TIFF REQUIRED)
  if (TIFF_FOUND)
    set (SL_INCLUDE_DIRS ${SL_INCLUDE_DIRS} ${TIFF_INCLUDE_DIR})
    set (SL_LIBRARIES ${SL_LIBRARIES} ${TIFF_LIBRARIES}) 
    message(STATUS "TIFF found")
  else (TIFF_FOUND)
    message(STATUS "TIFF NOT found.")
    message (FATAL_ERROR "You need libtiff to compile this program. Please install libs and developpement headers")
  endif (TIFF_FOUND)
endif(${smpp_BUILD_TOOLS})   


## #################################################################
## definitions
## #################################################################
add_definitions (${SL_DEFINITIONS})
include_directories (${SL_INCLUDE_DIRS})
link_directories(${SL_LIBRARY_DIRS})
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SL_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SL_CXX_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set (SL_LIBRARY_DIRS ${SL_LIBRARY_DIRS} CACHE STRING "SL libraries")
set (SL_INCLUDE_DIRS ${SL_INCLUDE_DIRS} CACHE STRING "SL include directories")
set (SL_LIBRARIES ${SL_LIBRARIES} CACHE STRING "SL 3rd party libraries")
#set (SL_DEFINITIONS ${SL_DEFINITIONS} CACHE STRING "SL_USE_XXX defines")
#set (SL_C_FLAGS ${SL_C_FLAGS}  CACHE STRING "c flags for cimg")
#set (SL_CXX_FLAGS ${SL_CXX_FLAGS} CACHE STRING "c++ flags for cimg")

message(STATUS "SL LIBRARIES:" ${SL_LIBRARIES})
