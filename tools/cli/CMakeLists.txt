############################################################
#
# $Id$
#
# Copyright (c) SMpp 2020
#
# AUTHOR:
# Sylvain Prigent
# 

# Project name
project(mppcli)

## #################################################################
## Define files
## #################################################################
include_directories(${smpp_SRC_INCLUDE_DIR})


## #################################################################
## Exe generation
## #################################################################
SET(NAME mpp)
SET(FILE ${SRC_FILES} main.cpp)
add_executable(${NAME} ${FILE} )
target_link_libraries(${NAME} smpp ${simageio_LIBRARIES})
