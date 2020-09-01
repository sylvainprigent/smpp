/// \file MppInteraction2D.h
/// \brief MppInteraction2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "smppExport.h"
#include "MppShape2D.h"

/// \class MppInteraction
/// \brief Interface to class that measure interaction between objects
class SMPP_EXPORT MppInteraction2D{

public:
    MppInteraction2D();
    ~MppInteraction2D();

public:
    virtual float run(MppShape2D* shape1, int x1, int y1, MppShape2D* shape2, int x2, int y2) = 0;
    
};
