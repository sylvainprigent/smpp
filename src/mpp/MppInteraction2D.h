/// \file MppInteraction2D.h
/// \brief MppInteraction2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "smppExport.h"
#include "MppShape2D.h"

/// \class MppInteraction
/// \brief Interface to measure interaction between objects
class SMPP_EXPORT MppInteraction2D{

public:
    /// \brief Constructor
    MppInteraction2D();
    /// \brief Destructor
    ~MppInteraction2D();

public:
    /// \brief Calculates the interaction
    /// \param[in] shape1 Reference centerd shape for the first shape candidate
    /// \param[in] x1 X position of the shape center 
    /// \param[in] y1 Y position of the shape center
    /// \param[in] shape2 Reference centerd shape for the second shape candidate
    /// \param[in] x2 X position of the shape center 
    /// \param[in] y2 Y position of the shape center
    virtual float run(MppShape2D* shape1, int x1, int y1, MppShape2D* shape2, int x2, int y2) = 0;
    
};
