/// \file MppDataTerm2D.h
/// \brief MppDataTerm2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "smppExport.h"
#include "MppShape2D.h"
#include "SImage2D.h"

/// \class MppDataTerm2D
/// \brief Interface for MPP data term in 2D
class SMPP_EXPORT MppDataTerm2D{

public:
    MppDataTerm2D(float threshold);
    MppDataTerm2D(SImage2D* image, float threshold);
    virtual ~MppDataTerm2D();

public:
    void set_image(SImage2D* image);
    SImage2D* image();

public:
    virtual float run(MppShape2D* shape, int x, int y) = 0;

protected:
    SImage2D* m_image;
    float m_threshold;
};
