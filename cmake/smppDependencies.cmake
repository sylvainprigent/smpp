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

if(${smpp_USE_OPENMP})
  find_package(OpenMP REQUIRED)
endif(${smpp_USE_OPENMP})  
