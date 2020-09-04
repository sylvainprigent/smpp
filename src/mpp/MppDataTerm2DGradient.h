/// \file MppDataTerm2DGradient.h
/// \brief MppDataTerm2DGradient class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "smppExport.h"
#include "MppDataTerm2D.h"

/// \class MppDataTerm2DGradient
/// \brief Define a data term as the gradient around the shape
class SMPP_EXPORT MppDataTerm2DGradient : public MppDataTerm2D{

public:
    /// \brief Constructor
    /// \param[in] threshold Threshold to select if the data term is heigh enough to keep the shape
    MppDataTerm2DGradient(float threshold);
    /// \brief Constructor
    /// \param[in] image Image where the data term is calculated
    /// \param[in] threshold Threshold to select if the data term is heigh enough to keep the shape
    MppDataTerm2DGradient(MppImageFloat* image, float threshold);
    /// \brief Destructor
    virtual ~MppDataTerm2DGradient();

public:
    /// \brief Setter for advanced parameter D.
    /// This parameter define the slope of the curve to transforme the gradient measure to [-1 1]
    /// \param[in] value Value of the parameter
    void set_D(float value);

public:
    /// \brief Method that implement the data term calculation
    /// a data term must be in [-1 1]. A good shape have a data term in [-1 0[ where the best shapes have a dataterm
    /// close to -1. Positive data term means bad shape.
    /// \param[in] shape Reference centerd shape
    /// \param[in] x X coordinate of the candidate shape center
    /// \param[in] y Y coordinate of the candidate shape center
    float run(MppShape2D* shape, int x, int y);

protected:
    /// \fn void init();
    /// \brief Precalculate the image gradient
    void init();

protected:
    float m_D; ///< Slope of the curve to transforme the distance to [-1 1]
    float* m_grad_image_x; ///< Image containing the gradient of the original image in x direction
    float* m_grad_image_y; ///< Image containing the gradient of the original image in y direction
};
