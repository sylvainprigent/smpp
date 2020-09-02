/// \file MppDraw2D.h
/// \brief MppDraw2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "MppShape2D.h"
#include "SImage.h"

/// \class MppDraw2D
/// \brief Draw shapes on an image
class MppDraw2D{

public:
    MppDraw2D(SImageFloat* image);

public:
    SImageChar* run(const std::vector<MppShape2D*>& shapes);

protected:
    SImageFloat* m_image;
};