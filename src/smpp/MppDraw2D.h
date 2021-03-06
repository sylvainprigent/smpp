/// \file MppDraw2D.h
/// \brief MppDraw2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "MppShape2D.h"
#include "simage/SImageFloat.h"
#include "simage/SImageUInt.h"

/// \class MppDraw2D
/// \brief Draw shapes on a 2D image
class MppDraw2D{

public:
    /// \brief Constructor
    /// \param[in] image Image to draw in
    MppDraw2D(SImageFloat* image);

public:
    /// \brief Does the drawing
    /// \param[in] shapes List of shapes to draw in the image
    /// \returns a pointer to a RGB 2D image with the shapes drew on it 
    SImageUInt* run(const std::vector<MppShape2D*>& shapes);

protected:
    SImageFloat* m_image; ///< Pointer to the input image

};
