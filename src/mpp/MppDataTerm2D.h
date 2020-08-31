/// \file MppDataTerm2D.h
/// \brief MppDataTerm2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "smppExport.h"
#include "MppShape2D.h"

/// \class MppDataTerm2D
/// \brief Interface for MPP data term in 2D
class SMPP_EXPORT MppDataTerm2D{

public:
    MppDataTerm2D();
    virtual ~MppDataTerm2D();

    virtual float run_2d(MppShape2D* shape1, int x1, int y1, MppShape2D* shape2, int x2, int y2) = 0;

};
