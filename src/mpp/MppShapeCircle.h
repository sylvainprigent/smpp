/// \file MppShapeCircle.h
/// \brief MppShapeCircle class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "smppExport.h"

#include "MppShape2D.h"

std::vector<MppPoint2D> compute_circle_coordinates(int x_center, int y_center, int radius);

/// \class MppShape
/// \brief Interface for shape container
class SMPP_EXPORT MppShapeCircle : public MppShape2D{

public:
    MppShapeCircle();
    MppShapeCircle(int x, int y, int r);
    virtual ~MppShapeCircle();

public:
    void set_x(const int & x);
    void set_y(const int & y);
    void set_r(const int & r);
    int x();
    int y();
    int r();

public:
    MppShape2D* copy();
    void translate(int x, int y); 

public:
    MppSilhouette2D* computeSilhouette(); 

protected:
    int m_x;
    int m_y;
    int m_r;
};