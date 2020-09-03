/// \file MppDataTerm2D.h
/// \brief MppDataTerm2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "smppExport.h"
#include "MppShape2D.h"
#include "MppImage.h"

/// \class MppDataTerm2D
/// \brief Interface for MPP data term in 2D
class SMPP_EXPORT MppDataTerm2D{

public:
    /// \brief Constructor
    /// \param[in] threshold Threshold to select if the data term is heigh enough to keep the shape
    MppDataTerm2D(float threshold);
    /// \brief Constructor
    /// \param[in] image Image where the data term is calculated
    /// \param[in] threshold Threshold to select if the data term is heigh enough to keep the shape
    MppDataTerm2D(MppImageFloat* image, float threshold);
    /// \brief Destructor
    virtual ~MppDataTerm2D();

public:
    /// \brief Setter for the image pointer
    /// \param[in] image Pointer to the image
    void set_image(MppImageFloat* image);
    /// \brief Getter for the image pointer
    /// \returns a Pointer to the image
    MppImageFloat* image();

public:
    /// \brief Method that implement the data term calculation
    /// a data term must be in [-1 1]. A good shape have a data term in [-1 0[ where the best shapes have a dataterm
    /// close to -1. Positive data term means bad shape.
    /// \param[in] shape Reference centerd shape
    /// \param[in] x X coordinate of the candidate shape center
    /// \param[in] y Y coordinate of the candidate shape center
    virtual float run(MppShape2D* shape, int x, int y) = 0;

protected:
    MppImageFloat* m_image; ///< Pointer to the image
    float m_threshold; ///< Threshold to define good shapes

};
