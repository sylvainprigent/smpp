/// \file MppDraw2D.h
/// \brief MppDraw2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "MppShape2D.h"
#include "SImage2D.h"

/// \class MppDraw
/// \brief Draw shapes on an image
class MppDraw2D{

public:
    MppDraw2D(SImage2D* image);

public:
    SImage2D* run(std::vector<MppShape2D*>* shapes);

protected:
    SImage2D* m_image;
};