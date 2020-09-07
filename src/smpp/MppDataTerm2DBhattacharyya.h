/// \file MppDataTerm2DBhattacharyya.h
/// \brief MppDataTerm2DBhattacharyya class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "smppExport.h"
#include "MppDataTerm2D.h"

/// \class MppDataTerm2DBhattacharyya
/// \brief Define a data term as the Bhattacharyya distance between the shape center and the shape contour
class SMPP_EXPORT MppDataTerm2DBhattacharyya : public MppDataTerm2D{

public:
    /// \brief Constructor
    /// \param[in] threshold Threshold to select if the data term is heigh enough to keep the shape
    MppDataTerm2DBhattacharyya(float threshold);
    /// \brief Constructor
    /// \param[in] image Image where the data term is calculated
    /// \param[in] threshold Threshold to select if the data term is heigh enough to keep the shape
    MppDataTerm2DBhattacharyya(MppImageFloat* image, float threshold);
    /// \brief Destructor
    virtual ~MppDataTerm2DBhattacharyya();

public:
    /// \brief Setter fot the max distance advanced parameter.
    /// This parameter define the slope of the curve to transforme the distance to [-1 1]
    /// \param[in] value Value of the parameter
    void set_max_distance(float value);
    /// \brief Setter for the shape contour width.
    /// By default the shape contour is 1.
    /// \param[in] value Value of the parameter
    void set_width(int value); 

public:
    /// \brief Implements precalculation needed for the data term
    void init();
    /// \brief Method that implement the data term calculation
    /// a data term must be in [-1 1]. A good shape have a data term in [-1 0[ where the best shapes have a dataterm
    /// close to -1. Positive data term means bad shape.
    /// \param[in] shape Reference centerd shape
    /// \param[in] x X coordinate of the candidate shape center
    /// \param[in] y Y coordinate of the candidate shape center
    float run(MppShape2D* shape, int x, int y);

protected:
    float m_max_distance; ///< Slope of the curve to transforme the distance to [-1 1]
    int m_width; ///< Width of the contour
};
